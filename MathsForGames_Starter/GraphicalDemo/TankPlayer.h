#pragma once

#include "SpriteObject.h"

namespace aie
{
	class TankPlayer : public SpriteObject
	{
	protected:
		void OnUpdate(float deltaTime) override;
	public:
		SpriteObject* Turret;
		class Projectile* Bullet;
	};
}