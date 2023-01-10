#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

#include "Tiles.hpp"

Tiles::Tiles(SDL_Renderer *p_renderer)
    : renderer(nullptr), textures(std::map<int, SDL_Texture *>())
{
    renderer = p_renderer;
    textures[1] = IMG_LoadTexture(renderer, "res/gfx/dirt.png");
};

SDL_Texture *Tiles::getTexture(int p_tileId)
{
    return textures[p_tileId];
};