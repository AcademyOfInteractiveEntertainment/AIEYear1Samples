#pragma once

#include "SpriteObject.h"

#include "Vector3.h"

namespace aie
{
	class Projectile : public SpriteObject
	{
	protected:
		void OnUpdate(float deltaTime) override;
	public:
		Projectile();

		Vector3 Velocity;
	};
}