
#include "Engine.h"
#include "SDL3/SDL.h"

#include <iostream>
#include <vector>

//Can use this to not have to type the namespace (like nu or std) every time. 
//using namespace nu;


int main()
{
    

    //INITIALIZATION
    nu::Renderer renderer;
    renderer.Initialize("Game Engine", 1280, 1024);

    //std::cout << sizeof(nu::Vector2) << std::endl;
    nu::Vector2 vel{ 0.5f , 0.0f };

    std::vector<nu::Vector2> v;
    nu::Vector2 v[300];

    for (int i = 0; i < 300; i++) 
    {
        
        v.push_back({ nu::RandomFloat(1280), nu::RandomFloat(1024) });
    }



    //handle events
    SDL_Event event;
    bool quit = false;


    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    //MAIN LOOP
    while (!quit) 
    {
        //UPDATE
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) 
            {
                quit = true;
            }
        }

        //RENDER
        renderer.SetColor(0, 0, 0);
        renderer.Clear();

        for (int i = 0; i < v.size(); i++) 
        {
            renderer.SetColorFloat(nu::RandomFloat(), nu::RandomFloat(), nu::RandomFloat());

            v[i] = v[i] + vel;
            renderer.DrawPoint(v[i].x, v[i].y);
        }

        renderer.SetColor(rand() % 256, rand() % 256, rand() % 256);
        renderer.DrawFillRect(nu::RandomFloat(40), nu::RandomFloat(40), 50, 50);

        //TODO: do these 2 later
        renderer.SetColor(255, 255, 255, 255);
        //renderer.
        //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set render draw color to white
        //SDL_RenderDebugText(renderer, 30, 30, "Hello World!");

        //TODO: make a line drawer. 


        renderer.Present();
    }

    //SHUTDOWN
    renderer.Shutdown();
    

    return 0;

}

