#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <vector>
#include <cmath>
#include <cstdio>

#include "Vector2.hpp"
#include "World.hpp"
#include "Chunk.hpp"
#include "Tile.hpp"

Chunk::Chunk(World *p_world, Vector2 p_pos)
    : world(p_world), pos(p_pos), updateRequired(true)
{
    tileMap = std::vector<std::vector<Tile *>>(64, std::vector<Tile *>(64));
    wrappedTileMap = std::vector<std::vector<Tile *>>(1, std::vector<Tile *>(1, nullptr));
};

void Chunk::updateChunk()
{
    for (int x = 0; x < 64; x++)
    {
        for (int y = 0; y < 64; y++)
        {
            tileMap[x][y]->tileUpdate();
        }
    }
    updateRequired = false;
}

TileMap &Chunk::getTileMap()
{
    return tileMap;
};

TileMap &Chunk::getWrappedTileMap()
{
    if (wrappedTileMap[0][0] == nullptr)
    {
        wrappedTileMap = std::vector<std::vector<Tile *>>(66, std::vector<Tile *>(66, new Tile(this, Vector2(1, 1))));

        for (int i = 0; i < 64; i++)
        {
            for (int j = 0; j < 64; j++)
            {
                wrappedTileMap[i + 1][j + 1] = tileMap[i][j];
            }
        }

        ChunkMap chunkMap = world->getChunkMap();

        if (pos.x > 0)
        {
            TileMap leftTiles = chunkMap[pos.x - 1][pos.y]->getTileMap();
            for (int i = 0; i < 64; i++)
            {
                wrappedTileMap[0][i + 1] = leftTiles[63][i];
            }
        }

        if (pos.x < world->size.x - 1)
        {
            TileMap rightTiles = chunkMap[pos.x + 1][pos.y]->getTileMap();
            for (int i = 0; i < 64; i++)
            {
                wrappedTileMap[65][i + 1] = rightTiles[0][i];
            }
        }

        if (pos.y > 0)
        {
            TileMap topTiles = world->getChunkMap()[pos.x][pos.y - 1]->getTileMap();
            for (int i = 0; i < 64; i++)
            {
                wrappedTileMap[i + 1][0] = topTiles[i][63];
            }

            if (pos.x > 0)
            {
                TileMap topLeftTiles = world->getChunkMap()[pos.x - 1][pos.y - 1]->getTileMap();
                wrappedTileMap[0][0] = topLeftTiles[63][63];
            }

            if (pos.x < world->size.x - 1)
            {
                TileMap topRightTiles = world->getChunkMap()[pos.x + 1][pos.y - 1]->getTileMap();
                wrappedTileMap[65][0] = topRightTiles[0][63];
            }
        }

        if (pos.y < world->size.y - 1)
        {
            TileMap bottomTiles = world->getChunkMap()[pos.x][pos.y + 1]->getTileMap();
            for (int i = 0; i < 64; i++)
            {
                wrappedTileMap[i + 1][65] = bottomTiles[i][0];
            }

            if (pos.x > 0)
            {
                TileMap bottomLeftTiles = world->getChunkMap()[pos.x - 1][pos.y + 1]->getTileMap();
                wrappedTileMap[0][65] = bottomLeftTiles[63][0];
            }

            if (pos.x < world->size.x - 1)
            {
                TileMap bottomRightTiles = world->getChunkMap()[pos.x + 1][pos.y + 1]->getTileMap();
                wrappedTileMap[65][65] = bottomRightTiles[0][0];
            }
        }
    }

    return wrappedTileMap;
}

void Chunk::setTile(Tile *tile, Vector2 pos) {
    tileMap[pos.x][pos.y] = tile;
}