#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argc, char *args[])
{

    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "STD INIT VIDEO HAS FAILED. SDL ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG INIT PNG HAS FAILED. IMG ERROR: " << SDL_GetError() << std::endl;

    SDL_ShowCursor(SDL_DISABLE);

    RenderWindow window("Game v1.0", 1280, 720);

    World dirt = World();

    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning)
    {

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }

        window.clear();
        window.render(dirt);
        window.controller->updateCursorPos();
        window.render(window.controller->cursor);
        window.display();

        SDL_Delay(16);

        window.controller->updateInputState();
    }

    window.cleanUp();
    IMG_Quit();
    SDL_Quit();

    return 0;
}
