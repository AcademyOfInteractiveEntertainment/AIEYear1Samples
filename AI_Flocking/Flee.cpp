#include "Flee.h"
#include "Agent.h"

Flee::Flee()
{
	m_targetPosition = nullptr;
}

Flee::~Flee()
{

}

void Flee::Update(float a_deltaTime, Agent& a_agent)
{
	if (m_targetPosition != nullptr)
	{
		// Get the distance between our position and the target position
		Vector2 distance = Vector2Subtract(a_agent.m_movementInfo.m_position , *m_targetPosition);

		// Normalize the direction
		Vector2 normal = Vector2Normalize(distance);

		// Calculate the force that will be added this frame
		Vector2 force = Vector2Subtract(Vector2Scale( normal , a_agent.m_movementInfo.m_maxSpeed) , a_agent.m_movementInfo.m_velocity);

		// Make sure its within the specified bounds
		force = Vector2Scale(Vector2Normalize(force) , a_agent.m_movementInfo.m_maxForce);

		// Add the force to the acceleration
		a_agent.m_movementInfo.m_acceleration =  Vector2Add( force , a_agent.m_movementInfo.m_acceleration);
	}
}
