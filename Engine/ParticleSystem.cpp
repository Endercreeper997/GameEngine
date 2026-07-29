#pragma once

#include "ParticleSystem.h"

namespace nu
{
	bool ParticleSystem::Initialize(size_t size)
	{
		// reserve # particles in container
		m_particles.resize(size);

		return true;
	}

	void ParticleSystem::Shutdown()
	{
		// clear all particles
		// TODO: clear() particles
	}

	void ParticleSystem::Update(float dt)
	{
		// update active particles
		for (auto& particle : m_particles)
		{
			if (/*TODO: particle is not active */) continue;

			// reduce particle.lifespan by subtracting delta time
			// TODO: particle.lifespan -= delta time

			// set active if (particle.lifespan > 0);
			// TODO: particle.active = particle lifespan > 0

			// update position with velocity (multiply by dt)
			// TODO: update position += with particle velocity * delta time
		}
	}

	void ParticleSystem::Draw(const Renderer& renderer)
	{
		// draw all active particlee
		for (auto& particle : m_particles)
		{
			if (particle.active)
			{
				// set particle color and draw point at current position
				// TODO: set color with particle color
				// TODO: draw point with particle position
			}
		}
	}

	void ParticleSystem::AddParticle(const Particle& particle)
	{
		// get free particle
		Particle* freeParticle = GetFreeParticle();
		// check if free particle is not nullptr
		if (freeParticle)
		{
			// set free particle object with particle
			*freeParticle = particle;
			// set particle active
			freeParticle->active = true;
		}
	}

	Particle* ParticleSystem::GetFreeParticle()
	{
		// find and return inactive particle 
		for (auto& particle : m_particles)
		{
			// return pointer to inactive particle
			if (!particle.active)
				return &particle;
		}

		// no free particles, return nullptr
		return nullptr;
	}

}