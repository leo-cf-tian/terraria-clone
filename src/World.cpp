#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <vector>
#include <cmath>
#include <cstdio>

#include "World.hpp"
#include "Vector2.hpp"
#include "Chunk.hpp"
#include "Tile.hpp"
#include "PerlinNoise.hpp"

World::World()
    : size(Vector2(10, 10))
{
    chunkMap = std::vector<std::vector<Chunk *>>(size.x, std::vector<Chunk *>(size.y));
    
    for (int x = 0; x < size.x; x++)
    {
        for (int y = 0; y < size.y; y++)
        {
            chunkMap[x][y] = new Chunk(this, Vector2(x, y));
        }
    }

    for (int x = 0; x < size.x * 64; x++)
    {
        float noise = PerlinNoise::perlin(Vector2((float)x, 1) / 20.0f) / 2 + 0.5f;
        for (int y = 0; y < size.y * 64; y++)
        {
            Tile *tile = new Tile(this->chunkMap[x / 64][y / 64], Vector2(x % 64, y % 64), y > (0.1 + noise * 0.1) * size.y * 64);
            
            chunkMap[x / 64][y / 64]->setTile(tile, Vector2(x % 64, y % 64));
        }
    }
};

ChunkMap &World::getChunkMap()
{
    return chunkMap;
};