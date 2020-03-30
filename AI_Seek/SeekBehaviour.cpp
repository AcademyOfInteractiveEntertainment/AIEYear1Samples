#include "SeekBehaviour.h"

Vector2 SeekBehaviour::Update(Agent* agent, float deltaTime)
{
	Vector2 v = Vector2Subtract(m_destination, agent->GetPosition());

	if (v.x == 0 && v.y == 0)
	{
		// if seeker on top of target, v is 0 so following calculations are not needed
		return { 0, 0 };
	}

	Vector2 desiredVelocity = Vector2Scale(Vector2Normalize(v), agent->GetMaxSpeed());
	Vector2 steeringForce = Vector2Subtract(desiredVelocity, agent->GetVelocity());

	return steeringForce;
}