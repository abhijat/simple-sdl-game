#ifndef SIMPLE_SDL_GAME_CLEANUP_HPP
#define SIMPLE_SDL_GAME_CLEANUP_HPP

#include <SDL2/SDL.h>

namespace simple_sdl_game
{

namespace resource_management
{

void cleanup(SDL_Window *window);

void cleanup(SDL_Renderer *renderer);

void cleanup(SDL_Texture *texture);

void cleanup(SDL_Surface *surface);

}

}

#endif //SIMPLE_SDL_GAME_CLEANUP_HPP
