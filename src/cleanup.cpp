#include "cleanup.hpp"

void simple_sdl_game::resource_management::cleanup(SDL_Window *window)
{
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

void simple_sdl_game::resource_management::cleanup(SDL_Renderer *renderer)
{
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
}

void simple_sdl_game::resource_management::cleanup(SDL_Texture *texture)
{
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

void simple_sdl_game::resource_management::cleanup(SDL_Surface *surface)
{
    if (surface != nullptr) {
        SDL_FreeSurface(surface);
    }
}

