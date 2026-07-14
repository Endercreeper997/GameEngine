#pragma once
#include "Renderer.h"
#include "Mesh.h"

namespace nu
{




	void Actor::Draw(const Renderer& renderer) const
	{
		renderer.DrawModel(m_model, m_transform)
		// renderer.SetColor(m_model.GetColor().r, m_model.GetColor().g, m_model.GetColor().b;

	}

}