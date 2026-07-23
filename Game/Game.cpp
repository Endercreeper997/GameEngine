
#include "Engine.h"
#include "SDL3/SDL.h"
#include "Player.h"
#include "Enemy.h"
#include "Assets.h"

#include <iostream>
#include <vector>

//Can use this to not have to type the namespace (like nu or std) every time. 
using namespace nu;


int main()
{
    Engine& e = Engine::Get();

    //INITIALIZATION
    e.Initialize();

    //std::vector<Vector2> points{{}}
    Mesh mesh{ { Vector2{ -3, 3 }, Vector2{ 3, 3 }, Vector2{ 0,0 } }, Color{ 0.0f, 0.0f, 1.0f } };
    Player player{ Transform{ Vector2{ 640.5f , 512.0f }, 0.0f, 50.0f }, { mesh } };

    //std::cout << sizeof(nu::Vector2) << std::endl;
    nu::Vector2 position{ 640.5f , 512.0f };
    nu::Vector2 velocity{ 0.0f , 0.0f };

    std::vector<nu::Vector2> points;

    uint64_t ticks = SDL_GetTicks();
    uint64_t prevTicks = ticks;
    float speed = 400.0f;
    
    

    /*for (int i = 0; i < 300; i++) 
    {
        
        v.push_back({ nu::RandomFloat(1280), nu::RandomFloat(1024) });
    }*/
    nu::Vector2 mousePosition;
    //handle events
    SDL_Event event;
   
    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };




    //mesh / model
    //std::vector<Vector2> points{{}}
    /* Color Vector(R, G, B)
    Vector2{ 1.0, 0.0, 0.0 },

        // Connected Lines
    
        */

    

    Scene scene;

    Player* player = new Player{ 2000.0f, Transform{ Vector2{640.0f, }};
    scene.AddActor(player);

    for (int i = 0; i < 20; i++)
    {
        Enemy* enemy = new Enemy{};
        scene.AddActor(enemy);
    }
   


    //photoshop
    std::vector<Vector2> points;

    //MAIN LOOP
    bool quit = false;
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
        Engine::Get().Update();

        player.SetRotation(player.GetTransform().rotation + (Engine::Get().GetTime().GetDeltaTime()));
        scene.Update(dt);

        
        if (Engine::Get().GetInput().GetButtonDown(nu::Input::MouseButton::Left))
        {
            if (points.empty()) 
            {
                points.push_back(Engine::Get().GetInput().GetMousePosition());
            }
            else
            {
                Vector2 v = points.back() - Engine::Get().GetInput().GetMousePosition();
                if (v.Length() > 10.0f)
                {
                    points.push_back(Engine::Get().GetInput().GetMousePosition());
                }
            }
        }

        
        
        

        /*
        velocity += (force * time.GetDeltaTime());
        position += (velocity * time.GetDeltaTime());

        position.x = Wrap(0.0f, 1280.0f, position.x);
        position.y = Wrap(0.0f, 1024.0f, position.y);*/


        //RENDER
        Engine::Get().GetRenderer().SetColorFloat(0.0f, 0.0f, 0.0f);

        

        Engine::Get().GetRenderer().Clear();

        for (int i = 0; i < (int)points.size() - 1; i++) 
        {
            Engine::Get().GetRenderer().SetColorFloat(nu::RandomFloat(), nu::RandomFloat(), nu::RandomFloat());
            Engine::Get().GetRenderer().DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        // character
        scene.Draw(Engine::Get().GetRenderer());

        Engine::Get().GetRenderer().Present();
    }
   
    //SHUTDOWN

    return 0;

}

