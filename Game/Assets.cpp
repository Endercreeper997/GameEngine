#include "Assets.h"
using namespace nu;

namespace Assets
{
    Mesh playerMesh{ 
        {
            Vector2{ -4, 5 },
            Vector2{ -4, -6 },
            Vector2{ -2, -7 },
            Vector2{ 3, -7 },
            Vector2{ 5, -6 },
            Vector2{ 5, -5 },
            Vector2{ 1, -5 },
            Vector2{ 0, -3 },
            Vector2{ 1, -2 },
            Vector2{ 5, -2 },
            Vector2{ 6, -3 },
            Vector2{ 5, -5 },
            Vector2{ 6, -3 },
            Vector2{ 5, -2 },
            Vector2{ 5, 5 },
            Vector2{ 2, 5 },
            Vector2{ 0, 2 },
            Vector2{ -1, 5 },
            Vector2{ -4, 5 },
            Vector2{ -4, 1 },
            Vector2{ -6, 1 },
            Vector2{ -6, -4 },
            Vector2{ -4, -4 }
            },
            Color{ 0.0f, 0.0f, 1.0f } 
    };
    Model playerModel{ std::vector<Mesh>{ mesh } };

}