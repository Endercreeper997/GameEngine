#pragma once
#include "Actor.h"


struct PlayerDesc : public nu::Actor;

class Player : nu::Actor
{
public:
	Player() = default;
	Player(const nu::Transform& transform) : 
		Actor{ transform }, 
		m_speed{ speed }
	{
	}
	Player(const nu::Transform& transform, const nu::Model& model) :
		Actor{ transform, model },
		m_speed{ speed }
	{
	}

	void Update(float dt) override;
	void Draw(const class Renderer& renderer) const override;



private:
	int m_ammo = 0;
};