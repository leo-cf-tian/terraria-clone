#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>

class Tiles
{
public:
    Tiles(SDL_Renderer *p_renderer);
    SDL_Texture *getTexture(int p_tileId);

private:
    SDL_Renderer *renderer;
    std::map<int, SDL_Texture *> textures;
};