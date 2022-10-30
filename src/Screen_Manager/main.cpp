#include <iostream>
#include <cstring>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Screen.hpp"
#include <SDL2/SDL.h>

using namespace DoubleSnake;

bool startWait(Screen &screen)
{
    bool starting = true;
    bool quit = false;
    while(starting){
        if(screen.processEvents() == Screen::Action::QUIT) {
            quit = true;
            starting = false;
        }
        if(screen.processEvents() == Screen::Action::MOVE_DOWN){
            starting = false;
        }
        else if(screen.processEvents() == Screen::Action::MOVE_UP){
            starting = false;
        }
        else if(screen.processEvents() == Screen::Action::MOVE_LEFT){
            starting = false;
        }
        else if(screen.processEvents() == Screen::Action::MOVE_RIGHT){
            starting = false;
        }
    }
    return quit;
}

bool pauseWait(Screen &screen, bool &pause)
{
    bool quit = false;
    while(pause){
        if(screen.processEvents() == Screen::Action::QUIT) {
            quit = true;
            pause = false;
        }
        if(screen.processEvents() == Screen::Action::PAUSE) {pause = false;}
    }
    return quit;
}


int main(int argc, char ** argv)
{
    Screen screen;
    if (!screen.init()) {
        SDL_Log("Error initializing screen");
        return -1;
    }

    bool pause = false;
    bool quit = false;
    bool fullscreen = false;

    while(!quit){
        //initalisation snake, screen.clear(), food, screen.update

        quit = startWait(screen); //wait player & verif if quit

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
                //TO DO
                break;
            case Screen::Action::MOVE_DOWN:
                //TO DO
                break;
            case Screen::Action::MOVE_LEFT:
                //TO DO
                break;
            case Screen::Action::MOVE_RIGHT:
                //TO DO
                break;
        }
        if(pause){//cas pause
            quit = pauseWait(screen, pause);
        }

        //screen.fullscreen(&fullscreen); //y'a un problème avec ça pour l'instant

        //déplacement du snake

    }
    return 0;
}
//g++ *.cpp `sdl2-config --cflags --libs` -lSDL2_ttf