#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include <string>

#ifndef SCREEN_HPP
#define SCREEN_HPP

typedef const int board;

namespace DoubleSnake {

    class Screen {
    public:
        enum Action {
            QUIT, PAUSE, FULLSCREEN, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT
        };//Action of the player
        static board S_WIDTH;
        static board S_HEIGHT;
    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_mainBuffer;
    public:
        //Create a Scene
        Screen();

        //Init window, renderer, texture, and buffer
        bool init();

        int processEvents();

        void update(int event, bool isGameOver);

        void setPixel(int x, int y, Uint32 color);

        void clear();

        void close();

        void drawGameOver();
    };
}

#endif //SCREEN_HPP
