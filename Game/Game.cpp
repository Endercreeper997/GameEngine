
#include "Engine.h"
#include "SDL3/SDL.h"

//Can use this to not have to type the namespace (like nu or std) every time. 
using namespace nu;

class Actor
{
public:
    Actor() = default;
    Actor(const Transform& transform) : m_transform { transform } {}

    void Update(float dt)
    {
  
        m_transform.position += (m_velocity * dt);
        m_velocity *= 0.997;

        m_transform.position.x = Wrap(0.0f, 1280.0f, m_transform.position.x);
        m_transform.position.y = Wrap(0.0f, 1024.0f, m_transform.position.y);
    }

    void Draw(const Renderer& renderer) 
    {
        renderer.SetColorFloat(1.0f, 1.0f, 1.0f);
        renderer.DrawFillRect(m_transform.position.x - (m_transform.scale * 0.5f), m_transform.position.y - (m_transform.scale * 0.5f), m_transform.scale, m_transform.scale);
    }

    const Transform& GetTransform() { return m_transform; }
    void SetPosition(const Vector3& position) { m_transform.position = position; }
    void SetRotation(float rotation) { m_transform.rotation = rotation; }
    void SetScale(float scale) { m_transform.scale = scale; }

    const Vector3& GetVelocity() { return m_velocity; }
    void SetVelocity(const Vector3& velocity) { m_velocity = velocity; }
    



protected:
    Transform m_transform;
    Vector3 m_velocity{ 0,0 };

};


int main()
{


    //INITIALIZATION
    nu::Renderer renderer;
    renderer.Initialize("Game Engine", 1280, 1024);

    nu::Input input;
    input.Initialize();

    nu::Time time;

    //std::vector<Vector2> points{{}}
    Mesh mesh{ { Vector3{ -3, 3 }, Vector3{ 3, 3 }, Vector3{ 0,0 } }, Color{ 0.0f, 0.0f, 1.0f } };


    Actor player{ Transform{ Vector2{ 640.5f , 512.0f }, 0.0f, 50.0f }, { mesh } };

    //std::cout << sizeof(nu::Vector2) << std::endl;
    nu::Vector3 position{ 640.5f , 512.0f };
    nu::Vector3 velocity{ 0.0f , 0.0f };

    std::vector<nu::Vector3> points;

    uint64_t ticks = SDL_GetTicks();
    uint64_t prevTicks = ticks;
    float speed = 400.0f;
    
    

    /*for (int i = 0; i < 300; i++) 
    {
        
        v.push_back({ nu::RandomFloat(1280), nu::RandomFloat(1024) });
    }*/
    nu::Vector3 mousePosition;
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
            if (points.empty()) 
            {
                points.push_back(input.GetMousePosition());
            }
            else
            {
                Vector3 v = points.back() - input.GetMousePosition();
                if (v.Length() > 10.0f)
                {
                    points.push_back(input.GetMousePosition());
                }
            }
        }

        nu::Vector3 force{ 0.0f , 0.0f };
        
        if (input.GetKeyDown(SDL_SCANCODE_A)) force.x = -speed;
        if (input.GetKeyDown(SDL_SCANCODE_D)) force.x = +speed;
        if (input.GetKeyDown(SDL_SCANCODE_W)) force.y = -speed;
        if (input.GetKeyDown(SDL_SCANCODE_S)) force.y = +speed;

        player.SetVelocity(player.GetVelocity() + (force * time.GetDeltaTime()));

        player.Update(time.GetDeltaTime());

        /*
        velocity += (force * time.GetDeltaTime());
        position += (velocity * time.GetDeltaTime());

        position.x = Wrap(0.0f, 1280.0f, position.x);
        position.y = Wrap(0.0f, 1024.0f, position.y);*/


        //RENDER
        renderer.SetColorFloat(0.0f, 0.0f, 0.0f);

        

        renderer.Clear();

        for (int i = 0; i < (int)points.size() - 1; i++) 
        {
            renderer.SetColorFloat(nu::RandomFloat(), nu::RandomFloat(), nu::RandomFloat());
            renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        // character
        player.Draw(renderer);
        //renderer.SetColorFloat(1.0f, 1.0f, 1.0f);
        //renderer.DrawFillRect(position.x - 20, position.y - 20, 40, 40);

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

