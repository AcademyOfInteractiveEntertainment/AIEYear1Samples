#include "Arrive.h"
#include "Agent.h"

Arrive::Arrive()
{
	m_targetPosition = nullptr;
}

Arrive::~Arrive()
{

}

void Arrive::Update(float a_deltaTime, Agent& a_agent)
{
	// If the target position hasn't been set the we can't do anything so return
	if (m_targetPosition == nullptr)
		return;

	// Calculate the distance between the target position and the agent position
	Vector2 distance =  Vector2Subtract(*m_targetPosition ,a_agent.m_movementInfo.m_position);

	// Get the direction of the distance
	Vector2 normal = Vector2Normalize(distance);
		
	// If the length of the direction is less m_distance(set by the user)
	//https://tenor.com/view/critical-role-crit-role-cr-arsequeef-matthew-mercer-gif-16312598
	if (Vector2Length(normal) < m_distance)
	{
		// Calculate the speed of the agent based on the distance
		Vector2 s = Vector2Scale(normal, (1.0f / (m_distance * a_agent.m_movementInfo.m_maxSpeed)));
		normal.x = normal.x * s.x;
		normal.y = normal.y * s.y;
	}
	else
	{
		// Set the speed to the max speed of the agent
		normal = Vector2Scale(normal, a_agent.m_movementInfo.m_maxSpeed);
	}

	// Calculate the force to add based on the normal vector
	Vector2 force = Vector2Subtract(normal , a_agent.m_movementInfo.m_velocity);
	
	// Cap it to max force
	force = Vector2Scale(Vector2Normalize(force) , a_agent.m_movementInfo.m_maxForce);

	// Apply the force to the agents acceleration
	a_agent.m_movementInfo.m_acceleration = Vector2Add(force, a_agent.m_movementInfo.m_acceleration);
}
