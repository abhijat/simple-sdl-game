#include "asset_loaders.hpp"

#include <iostream>

#include <SDL2/SDL_image.h>

SDL_Texture *simple_sdl_game::asset_load::load_texture(SDL_Renderer *renderer, const std::string &resource)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, resource.c_str());
    if (texture == nullptr) {
        std::cout << "load_texture error: " << SDL_GetError() << "\n";
    }

    return texture;
}