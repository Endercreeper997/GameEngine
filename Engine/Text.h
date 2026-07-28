#include "Font.h"
#include "Vector3.h"


struct SDL_Texture;

namespace nu
{
	class Renderer;
	struct Color;
	
	class Text {
	public:
		Text() = default;
		Text(Font* font) : m_font{ font } {}
		~Text();

		bool Create(Renderer& renderer, const std::string& text, const vec3& color);
		void Draw(Renderer& renderer, int x, int y);

	private:
		Font* m_font{ nullptr };
		SDL_Texture* m_texture{ nullptr };
	};
}