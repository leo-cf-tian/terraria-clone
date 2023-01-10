#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Camera.hpp"
#include "RenderWindow.hpp"

Camera::Camera(RenderWindow *p_window)
    : window(p_window)
{
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = window->dimensions.x;
    rect.h = window->dimensions.y;
    cameraRect = rect;
};

Vector2 Camera::updatePos(Vector2 p_pos)
{
    cameraRect.x = p_pos.x;
    cameraRect.y = p_pos.y;

    return Vector2(cameraRect.x, cameraRect.y);
}

Vector2 Camera::move(Vector2 p_pos)
{
    cameraRect.x += p_pos.x;
    cameraRect.y += p_pos.y;

    return Vector2(cameraRect.x, cameraRect.y);
}

SDL_Rect Camera::getRect()
{
    return cameraRect;
}