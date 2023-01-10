#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "World.hpp"
#include "Chunk.hpp"
#include "Tiles.hpp"
#include "Camera.hpp"
#include "Controller.hpp"

class Camera;

class RenderWindow
{
public:
    RenderWindow(const char *p_title, int p_w, int p_h);
    SDL_Texture *loadTexture(const char *p_filepath);
    void cleanUp();
    void clear();
    void render(Entity &p_entity);
    void render(Chunk &p_chunk, Vector2 p_chunkPos, SDL_Rect p_cameraRect);
    void render(World &p_world);
    void display();
    Vector2 dimensions;
    Vector2 updateCameraPos();
    Controller *controller;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Tiles tiles;
    Camera *camera;
};