#include "FleeBehaviour.h"

Vector2 FleeBehaviour::Update(Agent* agent, float deltaTime)
{
	if (m_target != nullptr)
	{
		Vector2 v = Vector2Subtract(agent->GetPosition(), m_target->GetPosition());

		float distance = Vector2Length(v);
		if (distance > 150)
			return { 0, 0 };

		if (v.x == 0 && v.y == 0)
		{
			// if seeker on top of target, v is 0 so following calculations are not needed
			return { 0, 0 };
		}

		Vector2 desiredVelocity = Vector2Scale(Vector2Normalize(v), m_maxSpeed);
		Vector2 steeringForce = Vector2Subtract(desiredVelocity, agent->GetVelocity());

		return steeringForce;
	}
	return { 0,0 };
}