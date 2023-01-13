#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "Vector2.hpp"

Entity::Entity(Vector2 p_pos, SDL_Texture *p_text)
    : pos(p_pos), texture(p_text)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 8;
    currentFrame.h = 8;
};

Entity::Entity(Vector2 p_pos, SDL_Texture *p_text, int p_width, int p_height)
    : pos(p_pos), texture(p_text)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = p_width;
    currentFrame.h = p_height;
};

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

SDL_Texture *Entity::getTexture()
{
    return texture;
}