#pragma once
#include "AABB.h"

namespace aie {
	class Renderer2D;
}

class GameObject
{
public:
	GameObject(Texture2D* m_texture, Vector2 position);
	~GameObject();
	
	void Update(float deltaTime);
	void Draw();

	Texture2D* m_texture;
	AABB m_bounds;
};

