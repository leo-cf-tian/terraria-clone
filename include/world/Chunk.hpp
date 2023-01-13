#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "Entity.hpp"
#include "Tile.hpp"
#include "World.hpp"

using TileMap = std::vector<std::vector<Tile *>>;

class World;

class Chunk
{
public:
    Chunk(World *p_world, Vector2 p_pos);
    void updateChunk();
    TileMap &getTileMap();
    TileMap &getWrappedTileMap();
    void setTile(Tile *tile, Vector2 pos);
    World *world;
    Vector2 pos;
    bool updateRequired;
    
private:
    TileMap tileMap;
    TileMap wrappedTileMap;
};