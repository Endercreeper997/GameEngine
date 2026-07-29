#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Assets.h"
#include "Renderer.h"
#include "Engine.h"
#include "SpaceGame.h"

void Player::Update(float dt)
{
    m_speed = 800.0f;
    //movement
    float thrust = 0.0f;

    if (nu::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = m_speed;
    if (nu::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -m_speed;

    float rotate = 0.0f;
    if (nu::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -100.0f;
    if (nu::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = 100.f;

    SetRotation(m_transform.rotation + rotate * dt);


    nu::Vector2 forward{ 1,0 };
    nu::Vector2 velocity = forward.Rotate(m_transform.rotation * nu::DegToRad) * thrust;
    AddVelocity(velocity * dt);

    //particle system
    nu::Particle particle;
    particle.position = m_transform.position;
    particle.color = { 1.0f, 1.0f, 1.0f };
    particle.lifespan = nu::RandomFloat(0.5f, 1.5f);
    particle.velocity = { nu::RandomFloat(-200.0f, 200.0f), nu::RandomFloat(-200.0f, 200.0f) };

    nu::Engine::Get().GetPS().AddParticle(particle);

    //fire
    if (nu::Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_SPACE))
    {
        BulletDesc desc;
        desc.name = "Bullet";
        desc.tag = "PlayerBullet";
        desc.model = Assets::bulletModel;
        desc.transform = m_transform;
        desc.damping = 3.0f;
        desc.speed = 4.0f;
        desc.lifespan = 1.0f;

        Bullet* bullet = new Bullet{ desc };
        m_scene->AddActor(bullet);

    }

    Actor::Update(dt);
}

void Player::OnCollision(Actor* other)
{
    if (other->GetName() == "Enemy")
    {
        SetDestroyed();

        ((SpaceGame*)m_scene->GetGame())->OnPlayerDead();
    }
}




