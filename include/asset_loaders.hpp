#ifndef SIMPLE_SDL_GAME_ASSET_LOADERS_HPP
#define SIMPLE_SDL_GAME_ASSET_LOADERS_HPP

#include <string>
#include <SDL2/SDL.h>

namespace simple_sdl_game
{

namespace asset_load
{

SDL_Texture *load_texture(SDL_Renderer *renderer, const std::string &resource);

}

}

#endif //SIMPLE_SDL_GAME_ASSET_LOADERS_HPP
