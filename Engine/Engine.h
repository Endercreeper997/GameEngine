#pragma once

#include "Vector2.h"
#include "Random.h"
#include "MathUtils.h"
#include "Text.h"

//Systems
#include "Renderer.h"
#include "Input.h"
#include "GameTime.h"
#include "Actor.h"
#include "Scene.h"
#include "Game.h"
#include "ParticleSystem.h"


#define ENGINE			Engine::Get()



namespace nu
{
	class Engine
	{
	public:

		static Engine& Get() { static Engine engine; return engine; }

		bool Initialize();
		void Shutdown();

		void Update();

		Input& GetInput() { return m_input; }
		Renderer& GetRenderer() { return m_renderer; }
		Time& GetTime() { return m_time; }
		ParticleSystem GetPS() { return m_particleSystem; }



	private:
		Engine() = default;

	private:
		Input m_input;
		Renderer m_renderer;
		ParticleSystem m_particleSystem;

		Time m_time;
	};

}