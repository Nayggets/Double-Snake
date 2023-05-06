#pragma once
#include <iostream>
#include <cstring>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

static struct SDLWindowDeleter
{
    void operator()(SDL_Window* w) const
    {
        SDL_DestroyWindow(w);
    }
}S_SDL_DeleteWindow;


static struct SDLRendererDeleter
{
    void operator()(SDL_Renderer* r) const
    {
        SDL_DestroyRenderer(r);
    }
}S_SDL_DeleteRenderer;


static struct SDLTextureDeleter
{
    void operator()(SDL_Texture* t) const
    {
        SDL_DestroyTexture(t);
    }
}S_SDL_DeleteTexture;
