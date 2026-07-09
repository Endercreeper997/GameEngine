#pragma once

#include <SDL3/SDL.h>

namespace nu
{
	class Renderer
	{
	public:
		bool Initialize(const char* name, int width, int height);
		void Shutdown();

		void Clear() const;
		void Present() const;

		void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255) const;
		void SetColorFloat(float r, float g, float b, float a = 255) const;

		void DrawPoint(float x, float y) const;
		void DrawFillRect(float x, float y, float w, float h) const;
		void DrawRect(float x, float y, float w, float h) const;
		void DrawLine(int x1, int y1, int x2, int y2) const;

	private:
		SDL_Window* m_window = nullptr;
		SDL_Renderer* m_renderer = nullptr;
	};
}
	