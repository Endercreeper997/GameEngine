#pragma once
#include "Enemy.h"
#include "Renderer.h"
#include "Engine.h"
#include "Player.h"

void Enemy::Update(float dt)
{
    Player* player = m_scene->GetActorByName<Player>("Player");
    if (player)
    {
        //TODO: fix this
        nu::Vector2 direction = player->GetTransform().position - m_transform.position;
        float rotation = direction.Angle();
        SetRotation(rotation * nu::RadToDeg);

        nu::Vector2 forward{ 1, 0 };
        forward = forward.Rotate(m_transform.rotation * nu::DegToRad);
        AddVelocity(forward * m_speed * dt);
    }



    Actor::Update(dt);
}

void Enemy::OnCollision(Actor* other)
{
    if (other->GetTag() == "PlayerBullet")
    {
        SetDestroyed();
        other->SetDestroyed();
    }
}


