#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include <string>
#include <vector>

#ifndef SCREEN_HPP
#define SCREEN_HPP

typedef const int board;


    class Screen {
    public:
        enum Action {
            QUIT, ESCAPE, PAUSE, FULLSCREEN, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, MOVE_U, MOVE_D, MOVE_L, MOVE_R
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

        void update();

        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

        void drawPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        
        void clear();

        void fullscreen(bool fullscreen);

        void close();

        void drawStart();

        void drawGameOver();

        void drawBitMap(std::vector<std::vector<int>> bitMap, int x, int y);
    };


#endif //SCREEN_HPP
