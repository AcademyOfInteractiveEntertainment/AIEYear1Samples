#include "Projectile.h"

namespace aie
{
	void Projectile::OnUpdate(float deltaTime)
	{
		LocalPosition += Velocity * deltaTime;
	}
	Projectile::Projectile()
	{
		Velocity = Vector3();
	}
}