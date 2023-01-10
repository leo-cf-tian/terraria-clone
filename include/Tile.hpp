#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Vector2.hpp"
#include "Chunk.hpp"

class Chunk;

class Tile
{
public:
    Tile(Chunk *p_chunk, Vector2 p_pos);
    Tile(Chunk *p_chunk, Vector2 p_pos, int p_id);
    Tile(Chunk *p_chunk, Vector2 p_pos, int p_id, int p_frame);
    ~Tile();
    int getId();
    void tileUpdate();
    void setFrame(int p_frame);
    SDL_Rect getFrame();
    SDL_Rect getFrame(int p_variant);

private:
    int id = 0;
    int frame = 0;
    int width = 8;
    int height = 8;
    Chunk *chunk;
    Vector2 pos;
};