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

    int ax=0;
    int ay=0;
    int x=0;
    int y=0;
    screen.setPixel(x,y,255,0,0);

    while(!quit){
        //TODO initalisation snake1, snake2,  food, corriger update()

        screen.clear();
        screen.setPixel(x,y,255,0,0);
        screen.update();

        if (starting) {
            quit = startWait(screen);
            starting = false;
        }

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
                std::cout << "up" << std::endl;
                ay=y;
                y-=16;
                break;
            case Screen::Action::MOVE_DOWN:
                std::cout << "down" << std::endl;
                ay=y;
                y+=16;
                break;
            case Screen::Action::MOVE_LEFT:
                std::cout << "left" << std::endl;
                ax=x;
                x-=16;
                break;
            case Screen::Action::MOVE_RIGHT:
                std::cout << "right" << std::endl;
                ax=x;
                x+=16;
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