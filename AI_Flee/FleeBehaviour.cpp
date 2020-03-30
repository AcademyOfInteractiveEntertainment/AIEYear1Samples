#include "FleeBehaviour.h"

Vector2 FleeBehaviour::Update(Agent* agent, float deltaTime)
{
	Vector2 v = Vector2Subtract(agent->GetPosition(), m_destination);

	float distance = Vector2Length(v);
	if (distance > m_fleeRadius)
		return { -agent->GetVelocity().x, -agent->GetVelocity().y };

	if (distance == 0)	// on top of destination
		v = { 1,0 };	// avoid errors when attempting to normalize a 0 vector

	Vector2 desiredVelocity = Vector2Scale(Vector2Normalize(v), agent->GetMaxSpeed());
	Vector2 steeringForce = Vector2Subtract(desiredVelocity, agent->GetVelocity());

	return steeringForce;
}