#include "Pursue.h"
#include "Agent.h"

Pursue::Pursue()
{
	m_targetPosition = nullptr;
	m_targetVelocity = nullptr;
}

Pursue::~Pursue()
{

}

void Pursue::Update(float a_deltaTime, Agent& a_agent)
{
	// If either the target position or velocity is nullptr then we can't do any calculations so return;
	if (m_targetPosition == nullptr || m_targetVelocity == nullptr)
		return;

	// Calculate the distance between the target and the agents position
	Vector2 originalDistance = Vector2Subtract(*m_targetPosition,a_agent.m_movementInfo.m_position);

	// Calculate how far to predict based on the distance between the target and the agent
	//float m_predictionAmount = glm::length(glm::normalize(originalDistance));
	
	// New target to seek to based on the targets velocity and the prediction amount
	Vector2 pursueTarget = Vector2Add( *m_targetPosition , *m_targetVelocity);// * m_predictionAmount;
	
	// Get the distance between the target position and our position
	Vector2 distance = Vector2Subtract( pursueTarget , a_agent.m_movementInfo.m_position);
	
	// Normalize the direction
	Vector2 normal = Vector2Normalize(distance);

	// Calculate the force that will be added this frame
	Vector2 force = Vector2Subtract(Vector2Scale(normal , a_agent.m_movementInfo.m_maxSpeed), a_agent.m_movementInfo.m_velocity);

	// Make sure its within the specified bounds
	force = Vector2Scale(Vector2Normalize(force) , a_agent.m_movementInfo.m_maxForce);

	// Add the force to the acceleration
	a_agent.m_movementInfo.m_acceleration = Vector2Add(force, a_agent.m_movementInfo.m_acceleration);
}