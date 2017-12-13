#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <asset_loaders.hpp>
#include <cleanup.hpp>

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "error initializing SDL" << "\n";
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
            "simple window",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            1024,
            768,
            SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        SDL_Quit();
        std::cout << "window error" << "\n";
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (renderer == nullptr) {
        SDL_Quit();
        std::cout << "renderer initialization error" << "\n";
        return 1;
    }

    SDL_RenderSetLogicalSize(renderer, 640, 352);

    const auto init_png_result = IMG_Init(IMG_INIT_PNG);
    if ((init_png_result & IMG_INIT_PNG) != IMG_INIT_PNG) {
        SDL_Quit();
        std::cout << "png init failed" << "\n";
        return 1;
    }

    if (TTF_Init() != 0) {
        SDL_Quit();
        std::cout << "ttf init failed" << "\n";
        return 1;
    }

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
        SDL_Quit();
        std::cout << "audio init failed" << "\n";
        return 1;
    }

    std::string resource_path{"../../res/"};
    SDL_Texture *texture = simple_sdl_game::asset_load::load_texture(renderer, resource_path + "map.png");
    if (texture == nullptr) {
        SDL_Quit();
        return 1;
    }

    SDL_Rect destination{};
    destination.x = 0;
    destination.y = 0;
    SDL_QueryTexture(texture, nullptr, nullptr, &destination.w, &destination.h);

    while (SDL_GetTicks() < 5000) {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, nullptr, &destination);
        SDL_RenderPresent(renderer);
    }

    simple_sdl_game::resource_management::cleanup(renderer);
    simple_sdl_game::resource_management::cleanup(window);
    simple_sdl_game::resource_management::cleanup(texture);

    SDL_Quit();

    std::cout << "exiting game" << "\n";
    return 0;
}

