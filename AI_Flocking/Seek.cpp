#include "Seek.h"
#include "Agent.h"


Seek::Seek()
{
	m_targetPosition = nullptr;
}

Seek::~Seek()
{

}

void Seek::Update(float a_deltaTime, Agent& a_agent)
{
	if (m_targetPosition != nullptr)
	{
		// Get the distance between the target position and our position
		Vector2 distance = Vector2Subtract( *m_targetPosition , a_agent.m_movementInfo.m_position);

		if (Vector2Length(distance) > 0)
		{
			// Normalize the direction
			Vector2 normal = Vector2Normalize(distance);

			// Calculate the force that will be added this frame
			Vector2 force = Vector2Subtract(Vector2Scale(normal, a_agent.m_movementInfo.m_maxSpeed), a_agent.m_movementInfo.m_velocity);

			// Make sure its within the specified bounds
			force = Vector2Scale(Vector2Normalize(force), a_agent.m_movementInfo.m_maxForce);

			// Add the force to the acceleration
			a_agent.m_movementInfo.m_acceleration = Vector2Add(force, a_agent.m_movementInfo.m_acceleration);
		}
	}
}
