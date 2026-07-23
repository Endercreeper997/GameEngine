#pragma once
#include "Vector3.h"

namespace nu
{

    struct Transform
    {
        Vector3 position;
        float rotation;
        float scale;
    };
}