#pragma once
#pragma once
#include "Actor.h"

class Enemy : nu::Actor
{
public:
	Enemy() = default;
	Enemy(const nu::Transform& transform) :
		Actor{ transform },
		m_speed{ speed }
	{
	}
	Enemy(const nu::Transform& transform, const nu::Model& model) :
		Actor{ transform, model },
		m_speed{ speed }
	{
	}

	void Update(float dt) override;
	void Draw(const class Renderer& renderer) const override;



private:
	int m_ammo = 0;
	float m_speed = 100.0f;
};