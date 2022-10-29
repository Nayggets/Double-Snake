#include <SDL2/SDL.h>
#include <iostream>
#ifdef __gnu_linux__
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#endif

#define WIDTH 1280
#define HEIGHT 720

bool running, fullscreen;

SDL_Renderer* renderer;
SDL_Window* window;

void update() {
    if(fullscreen) SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN);
    if(!fullscreen) SDL_SetWindowFullscreen(window,0);
}
void input() {
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT) {running = false;}
    }
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if(keystates[SDL_SCANCODE_ESCAPE]) running=false;
    if(keystates[SDL_SCANCODE_F11]) fullscreen = !fullscreen;
}
void draw() {
    SDL_SetRenderDrawColor(renderer, 40, 43, 200, 255);
    SDL_Rect rect;
    rect.x=rect.y=0;
    rect.w=WIDTH;
    rect.h=HEIGHT;
    SDL_RenderFillRect(renderer,&rect);

    SDL_RenderPresent(renderer);
}

int main()
{
    running = 1;
    fullscreen=0;
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {std::cout << "Failed at SDL_Init()" << std::endl;}
    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) {std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;}
    SDL_SetWindowTitle(window, "Double Snake");
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
    while (running){
        update();
        input();
        draw();
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}