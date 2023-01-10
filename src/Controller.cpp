#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Controller.hpp"

Controller::Controller(SDL_Renderer *p_renderer)
    : cursor(Entity(Vector2(0, 0), nullptr)), renderer(p_renderer)
{
    cursor = Entity(Vector2(0, 0), IMG_LoadTexture(renderer, "res/gfx/cursor.png"), 16, 16);
};

Vector2 Controller::updateCursorPos()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    cursor.pos = Vector2(x, y);
    return cursor.pos;
}

void Controller::updateInputState()
{
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);

    if (keyState[SDL_SCANCODE_UP] && !keyState[SDL_SCANCODE_DOWN])
        state.direction.y = -1;
    else if (!keyState[SDL_SCANCODE_UP] && keyState[SDL_SCANCODE_DOWN])
        state.direction.y = 1;
    else
        state.direction.y = 0;

    
    if (keyState[SDL_SCANCODE_LEFT] && !keyState[SDL_SCANCODE_RIGHT])
        state.direction.x = -1;
    else if (!keyState[SDL_SCANCODE_LEFT] && keyState[SDL_SCANCODE_RIGHT])
        state.direction.x = 1;
    else
        state.direction.x = 0;
}

ControllerState Controller::getState() {
    return state;
}