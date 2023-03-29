#pragma once
#include "ScreenMemoryManagement.hpp"


typedef const int board;

    class Screen {
        protected:
            Screen();
            static Screen* s_screen;
        public:
        //Create a Scene

        //Init window, renderer, texture, and buffer
        
        static Screen* GetInstance(){
            if(Screen::s_screen == nullptr){
                Screen::s_screen = new Screen();
            }
            return Screen::s_screen;
        }

        Screen(Screen &other) = delete;
        ~Screen();
        void operator=(const Screen &) = delete;
        
        int processEvents();

        void update();

        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

        void drawPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        
        void clear();

        void fullscreen(bool fullscreen);

        void drawStart();

        void drawGameOver();

        void drawBitMap(std::vector<std::vector<int>> bitMap, int x, int y);

        void drawText(int x,int y,int size,std::string str,SDL_Color color);



    public:
        enum Action {
            QUIT, ESCAPE, PAUSE, FULLSCREEN, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, MOVE_U, MOVE_D, MOVE_L, MOVE_R, ENTER
        };//Action of the player
        static board S_WIDTH;
        static board S_HEIGHT;
    private:

        std::unique_ptr<SDL_Window,SDLWindowDeleter> m_window;
        std::unique_ptr<SDL_Renderer,SDLRendererDeleter> m_renderer;
        std::unique_ptr<SDL_Texture,SDLTextureDeleter> m_texture;

        std::unique_ptr<Uint32[]> m_mainBuffer;
    };



