#pragma once
#include <SDL2/SDL.h>

#include "RenderWindow.hpp"
#include "Vector2.hpp"

class RenderWindow;

class Camera
{
public:
    Camera(RenderWindow *p_window);
    Vector2 updatePos(Vector2 p_pos);
    Vector2 move(Vector2 p_pos);
    SDL_Rect getRect();
private:
    SDL_Rect cameraRect;
    RenderWindow *window;
};
