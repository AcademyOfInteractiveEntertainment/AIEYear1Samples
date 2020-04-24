#include "Evade.h"
#include "Agent.h"

Evade::Evade()
{
	m_targetPosition = nullptr;
	m_targetVelocity = nullptr;
}

Evade::~Evade()
{

}

void Evade::Update(float a_deltaTime, Agent& a_agent)
{
	// If either the target positon or velocity is a nullptr then we can't do the calculations we need to so return
	if (m_targetPosition == nullptr || m_targetVelocity == nullptr)
		return;

	// Calculate the distance between the target and the agent
	Vector2 originalDistance = Vector2Subtract( *m_targetPosition , a_agent.m_movementInfo.m_position);
	
	// Calculate how much to predict by based on the distance
	float m_predictionAmount = Vector2Length(Vector2Normalize(originalDistance));

	// Calculate where the target will be in the future based on its velocity and the prediction amount
	Vector2 evadeTarget = Vector2Add (*m_targetPosition , Vector2Scale(*m_targetVelocity ,m_predictionAmount));

	// Get the distance between the target position and our position
	Vector2 distance = Vector2Subtract (a_agent.m_movementInfo.m_position , evadeTarget);

	// Normalize the direction
	Vector2 normal = Vector2Normalize(distance);

	// Calculate the force that will be added this frame
	Vector2 force = Vector2Subtract(Vector2Scale( normal , a_agent.m_movementInfo.m_maxSpeed) , a_agent.m_movementInfo.m_velocity);

	// Make sure its within the specified bounds
	force = Vector2Scale(Vector2Normalize(force) , a_agent.m_movementInfo.m_maxForce);

	// Add the force to the acceleration
	a_agent.m_movementInfo.m_acceleration = Vector2Add(force, a_agent.m_movementInfo.m_acceleration);
}