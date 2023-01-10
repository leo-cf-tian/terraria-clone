#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Vector2.hpp"
#include "Entity.hpp"

struct ControllerState
{
public:
    Vector2 direction;
    int space;
};

class Controller
{
public:
    Controller(SDL_Renderer *p_renderer);
    ControllerState getState();
    void updateInputState();

    Entity cursor;
    Vector2 updateCursorPos();

private:
    ControllerState state;
    SDL_Renderer *renderer;
};