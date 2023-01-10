#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Controller.hpp"

RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h)
    : dimensions(Vector2(p_w, p_h)), controller(nullptr), window(nullptr), renderer(nullptr), tiles(Tiles(nullptr)), camera(nullptr)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == nullptr)
        std::cout << "WINDOW FAILED TO INIT. ERROR: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    tiles = Tiles(renderer);
    controller = new Controller(renderer);
    camera = new Camera(this);
}

SDL_Texture *RenderWindow::loadTexture(const char *p_filepath)
{
    SDL_Texture *texture = nullptr;
    texture = IMG_LoadTexture(renderer, p_filepath);

    if (texture == nullptr)
        std::cout << "FAILED TO LOAD TEXTURE. ERROR " << SDL_GetError() << std::endl;

    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity &p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.pos.x;
    dst.y = p_entity.pos.y;
    dst.w = p_entity.getCurrentFrame().w;
    dst.h = p_entity.getCurrentFrame().h;

    SDL_RenderCopy(renderer, p_entity.getTexture(), &src, &dst);
}

void RenderWindow::render(Chunk &p_chunk, Vector2 p_chunkPos, SDL_Rect p_cameraRect)
{
    Vector2 chunkPos = p_chunkPos * 1024;

    bool withinX = chunkPos.x < p_cameraRect.x + p_cameraRect.w && p_cameraRect.x < chunkPos.x + 1024;
    bool withinY = chunkPos.y < p_cameraRect.y + p_cameraRect.h && p_cameraRect.y < chunkPos.y + 1024;

    if (withinX && withinY)
    {
        if (p_chunk.updateRequired)
            p_chunk.updateChunk();
        TileMap chunk = p_chunk.getTileMap();

        for (int x = 0; x < 64; x++)
        {
            for (int y = 0; y < 64; y++)
            {

                int tileId = chunk[x][y]->getId();

                if (tileId == 0)
                    continue;

                SDL_Rect src = chunk[x][y]->getFrame(1);

                SDL_Rect dst;
                dst.x = 16 * x + chunkPos.x - p_cameraRect.x;
                dst.y = 16 * y + chunkPos.y - p_cameraRect.y;
                dst.w = 16;
                dst.h = 16;

                SDL_RenderCopy(renderer, tiles.getTexture(tileId), &src, &dst);
            }
        }
    }
}

void RenderWindow::render(World &p_world)
{
    ChunkMap world = p_world.getChunkMap();

    camera->move(controller->getState().direction * 4);

    for (int x = 0; x < p_world.size.x; x++)
    {
        for (int y = 0; y < p_world.size.y; y++)
        {
            render(*world[x][y], Vector2(x, y), camera->getRect());
        }
    }
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}