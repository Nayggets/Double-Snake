#include "Screen.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <cstring>

#ifdef __gnu_linux__
#endif

typedef const int board;


    board Screen::S_WIDTH = 1280;
    board Screen::S_HEIGHT = 720;

    Screen::Screen(): m_window(NULL),m_renderer(NULL),m_texture(NULL),m_mainBuffer(NULL){}


    bool Screen::init()
    {
        //Initialize screen
        if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            std::cout << "Failed at SDL_Init()" << std::endl;
            return false;
        }
        if(TTF_Init() < 0){
            std::cerr << "Failed init TTF" << std::endl;
            return false; 
        }
        //Create window
        m_window = SDL_CreateWindow("DoubleSnake",
                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, S_WIDTH, S_HEIGHT,
                                    SDL_WINDOW_SHOWN);

        if (!m_window) {
            SDL_Log("Failed at SDL_CreateWindow()");
            SDL_Log("%s", SDL_GetError());
            SDL_Quit();
            return false;
        }

        //Create renderer
        m_renderer = SDL_CreateRenderer(m_window, -1,
                                        SDL_RENDERER_PRESENTVSYNC);

        if (!m_renderer) {
            SDL_Log("Failed at SDL_CreateRenderer()");
            SDL_Log("%s", SDL_GetError());
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        //Create Texture
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
                                      SDL_TEXTUREACCESS_STATIC, S_WIDTH, S_HEIGHT);

        if (!m_texture) {
            SDL_Log("Failed at SDL_CreateTexture()");
            SDL_Log("%s", SDL_GetError());
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        //Init buffer
        m_mainBuffer = new Uint32[S_WIDTH * S_HEIGHT];
        clear();
        return true;
    }

    int Screen::processEvents()
    {
        SDL_Event event;

        int action = -1; //No action

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    action = Action::QUIT;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_KP_ENTER:
                            action = Action::ENTER;
                            break;
                        case SDLK_F11:
                            action = Action::FULLSCREEN;
                            break;
                        case SDLK_ESCAPE:
                            action = Action::ESCAPE;
                            break;
                        case SDLK_LEFT:
                            action = Action::MOVE_LEFT;
                            break;
                        case SDLK_RIGHT:
                            action = Action::MOVE_RIGHT;
                            break;
                        case SDLK_DOWN:
                            action = Action::MOVE_DOWN;
                            break;
                        case SDLK_UP:
                            action = Action::MOVE_UP;
                            break;
                        case SDLK_SPACE:
                            action = Action::PAUSE;
                            break;
                        case SDLK_q:
                            action = Action::MOVE_L;
                            break;
                        case SDLK_d:
                            action = Action::MOVE_R;
                            break;
                        case SDLK_s:
                            action = Action::MOVE_D;
                            break;
                        case SDLK_z:
                            action = Action::MOVE_U;
                            break;
                    }
                    break;
            }
        }
        return action;
    }


    void Screen::update()
    {
        SDL_RenderPresent(m_renderer);
        SDL_UpdateTexture(m_texture, NULL, m_mainBuffer, S_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    }

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
    {
        SDL_SetRenderDrawColor(m_renderer, red, green, blue, 255);
        SDL_Rect rect;

        rect.x = x;
        rect.y = y;
        rect.w = 16;
        rect.h = 16;

        SDL_RenderFillRect(m_renderer, &rect);
    }
    
    void Screen::drawPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
    {
        SDL_SetRenderDrawColor(m_renderer, red, green, blue, 255);
        

        SDL_RenderDrawPoint(m_renderer,x,y);
    }

    void Screen::clear()
    {
        memset(m_mainBuffer, 0, S_WIDTH * S_HEIGHT * sizeof(Uint32));
    }

    void Screen::fullscreen(bool m_fullscreen)
    {
        if(m_fullscreen) SDL_SetWindowFullscreen(m_window,SDL_WINDOW_FULLSCREEN);
        if(!m_fullscreen) SDL_SetWindowFullscreen(m_window,0);
    }

    void Screen::close()
    {
        delete [] m_mainBuffer;

        SDL_DestroyTexture(m_texture);
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        TTF_Quit();
    }

    void Screen::drawStart() 
    {
        //TODO start
        setPixel(100,100,0,255,0);
        setPixel(200,200,0,255,0);
        update();
    }

    void Screen::drawGameOver() 
    {
        //TODO gameOver
    }

    void Screen::drawBitMap(std::vector<std::vector<int>> bitMap, int x, int y)
    {
        int copyX = x;
        for(auto& r : bitMap){
            copyX = x;
            for(auto& s : r){
                if(s == 1){
                    setPixel(copyX,y,255,0,255);
                }
                if(s == 2){
                    setPixel(copyX,y,0,255,0);
                }
                if(s == 3){
                    setPixel(copyX,y,0,0,255);
                }
                copyX++;
            }
            y++;
        }
    }

    void Screen::drawText(int x,int y,int size,std::string str,SDL_Color color)
    {
        TTF_Font* sans = TTF_OpenFont("Sans.ttf",size);
        SDL_Surface* surfaceMessage = TTF_RenderText_Solid(sans,str.c_str(),color);


        SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);

        SDL_Rect Message_rect; //create a rect
        Message_rect.x = x;  //controls the rect's x coordinate 
        Message_rect.y = y; // controls the rect's y coordinte
        Message_rect.w = 500; // controls the width of the rect
        Message_rect.h = 500; // controls the height of the rect

        // (0,0) is on the top left of the window/screen,
        // think a rect as the text's box,
        // that way it would be very simple to understand

        // Now since it's a texture, you have to put RenderCopy
        // in your game loop area, the area where the whole code executes

        // you put the renderer's name first, the Message,
        // the crop size (you can ignore this if you don't want
        // to dabble with cropping), and the rect which is the size
        // and coordinate of your texture
        SDL_RenderCopy(m_renderer, Message, NULL, NULL);
        SDL_RenderPresent(m_renderer);
        // Don't forget to free your surface and texture
        TTF_CloseFont(sans);
        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(Message);
    }




//V1

//#include "Screen.hpp"
//#include <SDL2/SDL.h>
//#include <iostream>
//#ifdef __gnu_linux__
//#endif
//
//#define WIDTH 1280
//#define HEIGHT 720
//
//bool running, m_fullscreen;
//
//SDL_Renderer* renderer;
//SDL_Window* window;
//
//void update() {
//    if(m_fullscreen) SDL_SetWindowm_fullscreen(window,SDL_WINDOW_m_fullscreen);
//    if(!m_fullscreen) SDL_SetWindowm_fullscreen(window,0);
//}
//void input() {
//    SDL_Event e;
//    while(SDL_PollEvent(&e)){
//        if(e.type == SDL_m_quit) {running = false;}
//    }
//    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
//    if(keystates[SDL_SCANCODE_ESCAPE]) running=false;
//    if(keystates[SDL_SCANCODE_F11]) m_fullscreen = !m_fullscreen;
//}
//void draw() {
//    SDL_SetRenderDrawColor(renderer, 40, 43, 200, 255);
//    SDL_Rect rect;
//    rect.x=rect.y=0;
//    rect.w=WIDTH;
//    rect.h=HEIGHT;
//    SDL_RenderFillRect(renderer,&rect);
//
//    SDL_RenderPresent(renderer);
//}
//
//int main()
//{
//    running = 1;
//    m_fullscreen=0;
//    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {std::cout << "Failed at SDL_Init()" << std::endl;}
//    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) {std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;}
//    SDL_SetWindowTitle(window, "Double Snake");
//    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
//    while (running){
//        update();
//        input();
//        draw();
//    }
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_m_quit();
//}
