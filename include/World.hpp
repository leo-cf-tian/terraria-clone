#pragma once

#include <vector>

#include "Vector2.hpp"
#include "Chunk.hpp"

using ChunkMap = std::vector<std::vector<Chunk *>>;

class World
{
public:
    World();
    ChunkMap &getChunkMap();
    Vector2 size;

private:
    ChunkMap chunkMap;
};