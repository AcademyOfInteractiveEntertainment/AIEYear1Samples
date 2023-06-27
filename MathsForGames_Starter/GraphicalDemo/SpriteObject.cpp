#include "SpriteObject.h"

#include "Utils.h"

namespace aie
{
    SpriteObject::SpriteObject()
    {
        Sprite = nullptr;
        Origin = Vector3(0.5f, 0.5f, 0.5f);
        Tint = Color(255, 255, 255, 255);
    }

    void SpriteObject::OnDraw()
    {
        // FACULTY: We could optimize this by calling GetWorldTransform to
        // retrieve all three values but that isn't a required part of
        // the assessment, so we pull them inefficiently here

        // extract transform data position
        Vector3 pos = GetWorldPosition();
        float rot = GetWorldRotation() * Rad2Deg;
        Vector3 scl = GetWorldScale();

        Sprite->Draw(
            raylib::Rectangle(0, 0, (float)Sprite->width, (float)Sprite->height),
            raylib::Rectangle(pos.x, pos.y, Sprite->width * scl.x, Sprite->height * scl.y),
            raylib::Vector2(Sprite->width * Origin.x * scl.x, Sprite->height * Origin.y * scl.y),
            rot,
            raylib::Color(Tint.rgba));
    }
}