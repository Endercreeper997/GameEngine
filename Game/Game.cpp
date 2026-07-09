
#include "Engine.h"
#include "SDL3/SDL.h"

//Can use this to not have to type the namespace (like nu or std) every time. 
using namespace nu;

struct Transform
{
    Vector2 position;
    float rotation;
    float scale;
};

class Actor
{
public:
    Actor(const Transform& transform) : m_transform { transform } {}

    void Update(float dt)
    {
  
        m_transform.position += (m_velocity * dt);

        m_transform.position.x = Wrap(0.0f, 1280.0f, m_transform.position.x);
        m_transform.position.y = Wrap(0.0f, 1024.0f, m_transform.position.y);
    }

    void Draw(const Renderer& renderer) 
    {
        renderer.SetColorFloat(1.0f, 1.0f, 1.0f);
        renderer.DrawFillRect(m_transform.position.x - (m_transform.scale * 0.5f), m_transform.position.y - (m_transform.scale * 0.5f), m_transform.scale, m_transform.scale);
    }


protected:
    Transform m_transform;
    Vector2 m_velocity{ 0,0 };

};


int main()
{
    

    //INITIALIZATION
    nu::Renderer renderer;
    renderer.Initialize("Game Engine", 1280, 1024);

    nu::Input input;
    input.Initialize();

    nu::Time time;

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
        time.Tick();

        //std::cout << seconds << " " << dt << std::endl;

        /*if (input.GetKeyPressed(SDL_SCANCODE_Q)) std::cout << "pressed\n";
        if (input.GetKeyDown(SDL_SCANCODE_Q)) std::cout << "down\n";
        if (input.GetKeyReleased(SDL_SCANCODE_Q)) std::cout << "released\n";

        if (input.GetButtonPressed(nu::Input::MouseButton::Left)) std::cout << "button pressed\n";
        if (input.GetButtonDown(nu::Input::MouseButton::Left)) std::cout << "button down\n";*/
        
        if (input.GetButtonDown(nu::Input::MouseButton::Left))
        {
            points.push_back(input.GetMousePosition());
        }

        nu::Vector2 force{ 0.0f , 0.0f };
        
        if (input.GetKeyDown(SDL_SCANCODE_A)) velocity.x = -speed;
        if (input.GetKeyDown(SDL_SCANCODE_D)) velocity.x = +speed;
        if (input.GetKeyDown(SDL_SCANCODE_W)) velocity.y = -speed;
        if (input.GetKeyDown(SDL_SCANCODE_S)) velocity.y = +speed;

        velocity += (force * time.GetDeltaTime());
        position += (velocity * time.GetDeltaTime());

        position.x = Wrap(0.0f, 1280.0f, position.x);
        position.y = Wrap(0.0f, 1024.0f, position.y);

        //RENDER
        renderer.SetColorFloat(0.0f, 0.0f, 0.0f);

        

        renderer.Clear();

        for (int i = 0; i < points.size(); i++) 
        {
            renderer.SetColorFloat(nu::RandomFloat(), nu::RandomFloat(), nu::RandomFloat());
            renderer.DrawFillRect(points[i].x, points[i].y, 10, 10);
        }

        // character
        renderer.SetColorFloat(1.0f, 1.0f, 1.0f);
        renderer.DrawFillRect(position.x - 20, position.y - 20, 40, 40);

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

