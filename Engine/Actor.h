#pragma once
#include "Model.h"
#include "Vector2.h"
#include "Vector3.h"
#include <string>

namespace nu 
{
    class Scene;

    struct ActorDesc
    {
        std::string name;
        std::string tag;
        Transform transform;
        Vector2 velocity{ 0.0f, 0.0f };

        Model model;
    };



    class Actor
    {
    public:
        Actor() = default;
        Actor(const ActorDesc& actorDesc) :
            m_name{ actorDesc.name },
            m_tag{ actorDesc.tag },
            m_transform{ actorDesc.transform },
            m_velocity{ actorDesc.velocity },
            m_model{ actorDesc.model }
        { }

        Actor(const Transform& transform) : m_transform{ transform } {}
        Actor(const Transform& transform, const Model& model) :
            m_transform{ transform },
            m_model{ model }
        { }

        virtual void Update(float dt)
        {

            m_transform.position += (m_velocity * dt);
            m_velocity *= 0.997;

            m_transform.position.x = Wrap(0.0f, 1280.0f, m_transform.position.x);
            m_transform.position.y = Wrap(0.0f, 1024.0f, m_transform.position.y);
        }

        virtual void Draw(const Renderer& renderer)
        {
            renderer.SetColorFloat(1.0f, 1.0f, 1.0f);
            renderer.DrawFillRect(m_transform.position.x - (m_transform.scale * 0.5f), m_transform.position.y - (m_transform.scale * 0.5f), m_transform.scale, m_transform.scale);
        }

        const Transform& GetTransform() { return m_transform; }
        void SetPosition(const Vector2& position) { m_transform.position = position; }
        void SetRotation(float rotation) { m_transform.rotation = rotation; }
        void SetScale(float scale) { m_transform.scale = scale; }

        const Vector2& GetVelocity() { return m_velocity; }
        void SetVelocity(const Vector2& velocity) { m_velocity = velocity; }
        void AddVelocity(const Vector2& velocity) { m_velocity += velocity; }

        const std::string& GetName();
        const std::string& GetTag();

        Scene* GetScene() { return m_scene; }

        friend Scene;

    protected:
        std::string m_name;
        std::string m_tag;


        Transform m_transform;
        Vector2 m_velocity{ 0, 0 };

        Model m_model;
        Scene* m_scene{ nullptr };
        
    };





}