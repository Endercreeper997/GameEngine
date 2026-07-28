
#include "Actor.h"




class Bullet : nu::Actor
{
public:
	Bullet() = default;
	Bullet(const nu::Transform& transform) :
		Actor{ transform },
		m_speed{ speed }
	{
	}
	Bullet(const nu::Transform& transform, const nu::Model& model) :
		Actor{ transform, model },
		m_speed{ speed }
	{
	}

	void Update(float dt) override;



private:
	int m_ammo = 0;
	float m_speed = 100.0f;
};