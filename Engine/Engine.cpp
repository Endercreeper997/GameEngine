

#include "pch.h"
#include "framework.h"
#include "Engine.h"

#include <iostream>


namespace nu
{
#pragma once

	bool Engine::Initialize() 
	{
		m_renderer.Initialize("Game Engine", 1280, 1024);
		m_particleSystem.Initialize();
		//audio
		m_input.Initialize();


		return true;
	}
	void Engine::Shutdown()
	{
		m_input.Shutdown();
		//audio
		m_renderer.Shutdown();
		m_particleSystem.Shutdown();
	}

	void Engine::Update()
	{
		m_time.Tick();
		m_input.Update();
		m_particleSystem.Update(m_time.GetDeltaTime());
	}
}