#include "Screen.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <unistd.h>

using namespace DoubleSnake;

bool startWait(Screen &screen)
{
    bool quit = false;
    bool starting = true;

    std::cout << "Appuyez sur une touche pour commencer" << std::endl;
    while(starting && !quit){
        int action = screen.processEvents();
        switch (action) {
            case Screen::Action::QUIT:
                quit = true;
                break;
            case Screen::Action::ESCAPE:
                quit = true;
                break;
            case Screen::Action::MOVE_LEFT:
                starting = false;
                break;
            case Screen::Action::MOVE_RIGHT:
                starting = false;
                break;
            case Screen::Action::MOVE_UP:
                starting = false;
                break;
            case Screen::Action::MOVE_DOWN:
                starting = false;
                break;
            case Screen::Action::MOVE_L:
                starting = false;
                break;
            case Screen::Action::MOVE_R:
                starting = false;
                break;
            case Screen::Action::MOVE_U:
                starting = false;
                break;
            case Screen::Action::MOVE_D:
                starting = false;
                break;
        }
    }
    return quit;
}


bool pauseWait(Screen &screen, bool &pause)
{
    bool quit = false;
    while(pause && !quit){
        int action = screen.processEvents();
        switch (action) {
            case Screen::Action::QUIT:
                quit = true;
                break;
            case Screen::Action::ESCAPE:
                quit = true;
                break;
            case Screen::Action::PAUSE:
                pause = false;
                break;
        }
    }
    return quit;
}


int main()
{
    Screen screen;
    if (!screen.init()) {
        SDL_Log("Error initializing screen");
        return -1;
    }

    bool pause = false;
    bool quit = false;
    bool fullscreen = false;
    bool starting = true;


    int x1=0;
    int y1=0;
    int x2=Screen::S_WIDTH-16;
    int y2=Screen::S_HEIGHT-16;

    screen.drawStart();

    while(!quit){

        if (starting) {
            quit = startWait(screen);
            starting = false;
        }

        screen.clear();
        //TODO initalisation snake1, snake2,  food
        if (x1 >= 0 && x1 < Screen::S_WIDTH && y1 >= 0 && y1 < Screen::S_HEIGHT) {
            screen.setPixel(x1,y1,255,0,0);
        }
        else{
            if(x1 < 0){//cas gauche
                x1 = Screen::S_WIDTH-16;
                screen.setPixel(x1,y1,255,0,0);
            }
            else if(x1 >= Screen::S_WIDTH){//cas droite
                x1 = 0;
                screen.setPixel(x1,y1,255,0,0);
            }
            else if(y1 < 0){//cas haut
                y1 = Screen::S_HEIGHT-16;
                screen.setPixel(x1,y1,255,0,0);
            }
            else if(y1 >= Screen::S_HEIGHT){//cas bas
                y1 = 0;
                screen.setPixel(x1,y1,255,0,0);
            }
        }

        screen.update();

        switch (screen.processEvents()) {
            case Screen::Action::QUIT:
                quit = true;
                break;
            case Screen::Action::ESCAPE:
                quit = true;
                break;
            case Screen::Action::PAUSE:
                pause = true;
                break;
            case Screen::Action::FULLSCREEN:
                if(fullscreen) {fullscreen = false;}
                else {fullscreen = true;}
                break;
            case Screen::Action::MOVE_UP:
                std::cout << "up1" << std::endl;
                y1-=16;
                break;
            case Screen::Action::MOVE_DOWN:
                std::cout << "down1" << std::endl;
                y1+=16;
                break;
            case Screen::Action::MOVE_LEFT:
                std::cout << "left1" << std::endl;
                x1-=16;
                break;
            case Screen::Action::MOVE_RIGHT:
                std::cout << "right1" << std::endl;
                x1+=16;
                break;
            case Screen::Action::MOVE_U:
                std::cout << "up2" << std::endl;
                y2-=16;
                break;
            case Screen::Action::MOVE_D:
                std::cout << "down2" << std::endl;
                y2+=16;
                break;
            case Screen::Action::MOVE_L:
                std::cout << "left2" << std::endl;
                x2-=16;
                break;
            case Screen::Action::MOVE_R:
                std::cout << "right2" << std::endl;
                x2+=16;
                break;
        }
        if(pause){
            std::cout << "pause" << std::endl;
            quit = pauseWait(screen, pause);
            std::cout << "fin pause" << std::endl;
        }

        screen.fullscreen(fullscreen);


        //TODO déplacement du snake

    }
    screen.close();
    return 0;
}
//g++ *.cpp `sdl2-config --cflags --libs` -lSDL2_ttf