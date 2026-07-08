
#include "Engine.h"
#include "SDL3/SDL.h"

//Can use this to not have to type the namespace (like nu or std) every time. 
//using namespace nu;


int main()
{
    

    //INITIALIZATION
    nu::Renderer renderer;
    renderer.Initialize("Game Engine", 1280, 1024);

    nu::Input input;
    input.Initialize();

    //std::cout << sizeof(nu::Vector2) << std::endl;
    nu::Vector2 vel{ 0.5f , 0.0f };

    std::vector<nu::Vector2> v;
    

    for (int i = 0; i < 300; i++) 
    {
        
        v.push_back({ nu::RandomFloat(1280), nu::RandomFloat(1024) });
    }

    nu::Vector2 mousePosition;



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
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.scancode == SDL_SCANCODE_ESCAPE)
            {
                quit = true;
            }
        }

        //engine update
        input.Update();

        if (input.GetKeyPressed(SDL_SCANCODE_Q)) std::cout << "pressed\n";
        if (input.GetKeyDown(SDL_SCANCODE_Q)) std::cout << "down\n";
        if (input.GetKeyReleased(SDL_SCANCODE_Q)) std::cout << "released\n";

        if (input.GetButtonPressed(nu::Input::MouseButton::Left)) std::cout << "button pressed\n";
        if (input.GetButtonDown(nu::Input::MouseButton::Left)) std::cout << "button down\n";
        


        //RENDER
        renderer.SetColorFloat(0.0f, 0.0f, 0.0f);
        renderer.Clear();

        for (int i = 0; i < v.size(); i++) 
        {
            renderer.SetColorFloat(nu::RandomFloat(), nu::RandomFloat(), nu::RandomFloat());

            //v[i] = v[i] + vel;
            renderer.DrawPoint(v[i].x, v[i].y);
        }

        renderer.SetColorFloat(1.0f, 1.0f, 1.0f);
        renderer.DrawFillRect(input.GetMousePosition().x - 20, input.GetMousePosition().y - 20, 40, 40);

        /*
        renderer.SetColor(rand() % 256, rand() % 256, rand() % 256);
        renderer.DrawFillRect(nu::RandomFloat(40), nu::RandomFloat(40), 50, 50);
        */
        //renderer.SetColor(255, 255, 255, 255);
        



        renderer.Present();
    }

    //SHUTDOWN
    renderer.Shutdown();
    

    return 0;

}

