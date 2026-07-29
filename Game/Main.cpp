
#include "Engine.h"
#include "SDL3/SDL.h"
#include "Player.h"
#include "Enemy.h"
#include "Assets.h"
#include "SpaceGame.h"
#include "fmod.hpp"

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

//Can use this to not have to type the namespace (like nu or std) every time. 
using namespace nu;


int main()
{

    //INITIALIZATION
    //SetWorkingDirectory("Assets");
    Engine::Get().Initialize();
  

    SpaceGame game;
    game.Initialize();


    //Audio stuff
      // create audio system
    FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

    FMOD::Sound* sound = nullptr;
    audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);

    audio->playSound(sound, 0, false, nullptr);

    //add extra sfx to test
    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

    std::vector<FMOD::Sound*> sounds;

    FMOD::Sound* sound = nullptr;
    audio->createSound("whistle.mp3", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("error.mp3", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("mario.mp3", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    //sound input test
    if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_1))
    {
        audio->playSound(sounds[0], nullptr, false, nullptr);
    }

    if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_2))
    {
        audio->playSound(sounds[1], nullptr, false, nullptr);
    }
    if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_3))
    {
        audio->playSound(sounds[2], nullptr, false, nullptr);
    }
    if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_4))
    {
        audio->playSound(sounds[3], nullptr, false, nullptr);
    }
    if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_5))
    {
        audio->playSound(sounds[4], nullptr, false, nullptr);
    }


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

        //Game
        game.Update(dt);
        audio->update();


        //RENDER
        Engine::Get().GetRenderer().SetColorFloat(0.0f, 0.0f, 0.0f);
        Engine::Get().GetRenderer().Clear();


        game.Draw(Engine::Get().GetRenderer());
        Engine::Get().GetPS().Draw(Engine::Get().GetRenderer());
        Engine::Get().GetRenderer().Present();
    }
   
    //SHUTDOWN
    Engine::Get().Shutdown();

    return 0;

}

