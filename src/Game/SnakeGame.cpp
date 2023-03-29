#include "SnakeGame.hpp"

SnakeGame::SnakeGame()
    : m_snakeOne{128,128,2},
      m_snakeTwo{256,256,1},
      m_theMagicalFruit{512,512},
      m_toCheckCollide{}    
{
    m_run = true;
    m_screen = Screen::GetInstance();

}

SnakeGame::~SnakeGame()
{

}

void SnakeGame::startWait()
{
    m_quit = false;
    m_starting = true;

    std::cout << "Appuyez sur une touche pour commencer" << std::endl;
    while(m_starting && !m_quit){
        int action = m_screen->processEvents();
        switch (action) {
            case Screen::Action::QUIT:
                m_quit = true;
                break;
            case Screen::Action::ESCAPE:
                m_quit = true;
                break;
            case Screen::Action::MOVE_LEFT:
                m_starting = false;
                break;
            case Screen::Action::MOVE_RIGHT:
                m_starting = false;
                break;
            case Screen::Action::MOVE_UP:
                m_starting = false;
                break;
            case Screen::Action::MOVE_DOWN:
                m_starting = false;
                break;
            case Screen::Action::MOVE_L:
                m_starting = false;
                break;
            case Screen::Action::MOVE_R:
                m_starting = false;
                break;
            case Screen::Action::MOVE_U:
                m_starting = false;
                break;
            case Screen::Action::MOVE_D:
                m_starting = false;
                break;
        }
    }
}


void SnakeGame::pauseWait()
{
    bool m_quit = false;
    while(m_pause && !m_quit){
        int action = m_screen->processEvents();
        switch (action) {
            case Screen::Action::QUIT:
                m_quit = true;
                break;
            case Screen::Action::ESCAPE:
                m_quit = true;
                break;
            case Screen::Action::PAUSE:
                m_pause = false;
                break;
        }
    }
}

void SnakeGame::checkProcessEvent()
{
    switch (m_screen->processEvents()) {
        case Screen::Action::ENTER:
            m_endMenu = false;
            break;
        case Screen::Action::QUIT:
            m_quit = true;
            break;
        case Screen::Action::ESCAPE:
            m_quit = true;
            break;
        case Screen::Action::PAUSE:
            m_pause = true;
            break;
        case Screen::Action::FULLSCREEN:
            if(m_fullscreen) {m_fullscreen = false;}
            else {m_fullscreen = true;}
            break;
        case Screen::Action::MOVE_UP:
            std::cout << "up1" << std::endl;
            m_moove = 4;
            break;
        case Screen::Action::MOVE_DOWN:
            std::cout << "down1" << std::endl;
            m_moove = 2;
            break;
        case Screen::Action::MOVE_LEFT:
            std::cout << "left1" << std::endl;
            m_moove = 1;
            break;
        case Screen::Action::MOVE_RIGHT:
            std::cout << "right1" << std::endl;
            m_moove = 3;
            break;
        case Screen::Action::MOVE_U:
            std::cout << "up2" << std::endl;
            m_moove2 = 4;
            break;
        case Screen::Action::MOVE_D:
            std::cout << "down2" << std::endl;
            m_moove2 = 2;
            break;
        case Screen::Action::MOVE_L:
            std::cout << "left2" << std::endl;
            m_moove2 = 1;
            break;
        case Screen::Action::MOVE_R:
            std::cout << "right2" << std::endl;
            m_moove2 = 3;
            break;
        default:
            break;
    }
}

void SnakeGame::globalDraw()
{
    m_screen->clear();
    m_snakeOne.draw(*m_screen);
    m_snakeTwo.draw(*m_screen);
    m_theMagicalFruit.draw(*m_screen);
    m_screen->update();
}

void SnakeGame::globalUpdate()
{
    m_snakeOne.update(m_moove);
    m_snakeTwo.update(m_moove2);
}

void SnakeGame::globalCheckCollide()
{
    /*check collide between snake and fruitz*/
    if(m_snakeOne.checkCollideWithOther(m_theMagicalFruit)){
        m_snakeOne.addBody();
        m_theMagicalFruit.eaten();
    }
    else if(m_snakeTwo.checkCollideWithOther(m_theMagicalFruit)){
        m_snakeTwo.addBody();
        m_theMagicalFruit.eaten();
    }
    
    /*check collide between the two snake*/
    m_toCheckCollide = m_snakeOne.allBody();
    for(auto& s : m_toCheckCollide){
        if(m_snakeTwo.checkCollideWithOther(s)){
            m_run = false;
            m_snakeTwoDead = true;
        }
    }
    m_toCheckCollide.clear();
    m_toCheckCollide = m_snakeTwo.allBody();
    for(auto& s : m_toCheckCollide){
        if(m_snakeOne.checkCollideWithOther(s)){
            m_run = false;
            m_snakeOneDead = true;
        }
    }
    
    /*check collide between a snake and his body*/
    m_toCheckCollide.clear();
    m_toCheckCollide = m_snakeTwo.allBodyWithoutHead();

    for(auto& s : m_toCheckCollide){
        if(m_snakeTwo.checkCollideWithOther(s)){
            m_run = false;
            m_snakeTwoDead = true;
        }
    }
    m_toCheckCollide.clear();
    m_toCheckCollide = m_snakeOne.allBodyWithoutHead();

    for(auto& s : m_toCheckCollide){
        if(m_snakeOne.checkCollideWithOther(s)){
            m_run = false;
            m_snakeOneDead = true;
        }
    }
}

void SnakeGame::run()
{
    while(m_run && !m_quit){

        m_delta += m_tickAtEnd - m_tickAtStart;
        m_tickAtStart = SDL_GetTicks();


        if (m_starting) {
            startWait();
            m_starting = false;
        }
        checkProcessEvent();

            
        if (m_delta > 1000/10.0)
        {
            m_delta = 0;
            globalUpdate();
            globalDraw();
            globalCheckCollide();
        }

            if(m_pause){
                std::cout << "pause" << std::endl;
                pauseWait();
                std::cout << "fin pause" << std::endl;
            }

            m_screen->fullscreen(m_fullscreen);

            
            //TODO déplacement du snake
            m_tickAtEnd = SDL_GetTicks();

    }

    gameOver();
}

void SnakeGame::gameOver()
{
    SDL_Color White = {255,255,255};

    

    checkProcessEvent();
    m_endMenu = true;
    while(m_endMenu && !m_quit)
    {
        m_screen->clear();
        m_screen->drawText(512,512,12,"Game Over",White);
        m_screen->update();
        checkProcessEvent();

    }
    free(m_screen);

}

void SnakeGame::launch()
{
    std::vector<Body> temp;
    m_screen->drawStart();


    m_screen->clear();
    m_snakeOne.draw(*m_screen);
    m_snakeTwo.draw(*m_screen);
    m_screen->update();
    this->run();
}