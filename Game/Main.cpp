
#include "Engine.h"
#include "SDL3/SDL.h"
#include "Player.h"
#include "Enemy.h"
#include "Assets.h"
#include "SpaceGame.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

//Can use this to not have to type the namespace (like nu or std) every time. 
using namespace nu;


int main()
{

    //INITIALIZATION
    SetWorkingDirectory("Assets");
    Engine::Get().Initialize();
  

    SpaceGame game;
    game.Initialize();

    Font* font = new Font();
    font->Load("fonts/BreatheFireIii-PKLOB.ttf", 65);

    Text* text = new Text(font);
    text->Create(Engine::Get().GetRenderer(), "Hello World", Color{1, 1, 1, 1});


    //Audio stuff


    //Player setup
    Scene scene;


    //handle events
    SDL_Event e;

    
    nu::Vector2 mousePosition;
   



    //photoshop
    std::vector<Vector2> points;

    //MAIN LOOP
    bool quit = false;

    while (!quit) 
    {
        //UPDATE
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) 
            {
                quit = true;
            }
            if (e.type == SDL_EVENT_KEY_DOWN && e.key.scancode == SDL_SCANCODE_ESCAPE)
            {
                quit = true;
            }
        }

        //engine update
        Engine::Get().Update();
        float dt = Engine::Get().GetTime().GetDeltaTime();

        game.Update(dt);
        scene.Update(dt);

        
        //painting stuff
        /*
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
        */
        
        
        

        /*
        velocity += (force * time.GetDeltaTime());
        position += (velocity * time.GetDeltaTime());

        position.x = Wrap(0.0f, 1280.0f, position.x);
        position.y = Wrap(0.0f, 1024.0f, position.y);*/


        //RENDER
        Engine::Get().GetRenderer().SetColorFloat(0.0f, 0.0f, 0.0f);
        Engine::Get().GetRenderer().Clear();


        game.Draw(Engine::Get().GetRenderer());
        scene.Draw(Engine::Get().GetRenderer());
        text->Draw(Engine::Get().GetRenderer(), 40.0f, 40.0f);
        

        Engine::Get().GetRenderer().Clear();

        for (int i = 0; i < (int)points.size() - 1; i++) 
        {
            Engine::Get().GetRenderer().SetColorFloat(nu::RandomFloat(), nu::RandomFloat(), nu::RandomFloat());
            Engine::Get().GetRenderer().DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }


        Engine::Get().GetRenderer().Present();
    }
   
    //SHUTDOWN
    Engine::Get().Shutdown();

    return 0;

}

