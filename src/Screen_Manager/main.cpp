#include <iostream>
#include <cstring>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Screen.hpp"
#include <SDL2/SDL.h>

using namespace DoubleSnake;

int main(int argc, char ** argv) {
    Screen screen;
    if (!screen.init()) {
        SDL_Log("Error initializing screen");
        return -1;
    }
    return 0;
}
//g++ *.cpp `sdl2-config --cflags --libs` -lSDL2_ttf