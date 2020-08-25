#include "ArriveBehaviour.h"

bool ArriveBehaviour::Update(Agent* agent, float deltaTime)
{
	Vector2 desiredVelocity = Vector2Subtract(m_destination, agent->GetPosition());
	float distance = Vector2Length(desiredVelocity);

	// Check the distance to detect whether the character
	// is inside the slowing area
	if (distance < m_slowingRadius) 
	{
		// Inside the slowing area
		desiredVelocity = Vector2Scale(Vector2Normalize(desiredVelocity), agent->GetMaxSpeed() * (distance / m_slowingRadius));
	}
	else {
		// Outside the slowing area.
		desiredVelocity = Vector2Scale(Vector2Normalize(desiredVelocity), agent->GetMaxSpeed());
	}

	// Set the steering based on this
	Vector2 steeringForce = Vector2Subtract(desiredVelocity, agent->GetVelocity());
	agent->AddForce(steeringForce);

	return true;
}