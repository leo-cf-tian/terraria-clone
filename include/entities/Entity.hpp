#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Vector2.hpp"

class Entity
{
public:
    Entity(Vector2 p_pos, SDL_Texture *p_text);
    Entity(Vector2 p_pos, SDL_Texture *p_text, int p_width, int p_height);
    Vector2 pos;
    SDL_Rect getCurrentFrame();
    SDL_Texture *getTexture();
protected:
    SDL_Rect currentFrame;
    SDL_Texture *texture;
};