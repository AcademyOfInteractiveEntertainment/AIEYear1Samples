#pragma once

// NOTE: Sub-optimal to include here, but simplifies things greatly
#include "raylib-cpp.hpp"

#include "Color.h"
#include "GameObject.h"

namespace aie
{
    class SpriteObject : public GameObject
    {
    public:
        raylib::Texture2D* Sprite;
        Vector3 Origin;

        Color Tint;

        SpriteObject();

    protected:
        void OnDraw() override;
    };
}