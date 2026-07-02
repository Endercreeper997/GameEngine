
#include "Engine.h"
#include "SDL3/SDL.h"

#include <iostream>




int main()
{
    
    nu::Renderer renderer;
    renderer.Initialize("Game Engine", 1920, 1024);



    //handle events
    SDL_Event e;
    bool quit = false;


    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }


        renderer.SetColor(0, 0, 0);
        renderer.Clear();

        for (int i = 0; i < 1000; i++) {
            renderer.SetColor(rand() % 256, rand() % 256, rand() % 256);
            renderer.DrawPoint(rand() % 1280, rand() % 1024);
        }

        renderer.SetColor(rand() % 256, rand() % 256, rand() % 256);
        renderer.DrawFillRect(40, 40, 50, 50);

        //TODO: do these 2 later
        renderer.SetColor(255, 255, 255, 255);
        //renderer.
        //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set render draw color to white
        //SDL_RenderDebugText(renderer, 30, 30, "Hello World!");

        //TODO: make a line drawer. 

        renderer.Present();
    }

    renderer.Shutdown();
    

    return 0;

}

