#include "Wander.h"
#include "Agent.h"

#include <random>

Wander::Wander()
{
	// Set defaults
	m_targetPosition = Vector2();
	m_angleStepping			= 0.0f;
	m_timeStepping			= 0.0f;
	m_currentTimeStepping	= 0.0f;
}

Wander::~Wander()
{
	
}

void Wander::Update(float a_deltaTime, Agent& a_agent)
{
	
	// Increase the current time by delta time
	m_currentTimeStepping += a_deltaTime;

	// Check if its greater than the time stepping
	if (m_currentTimeStepping >= m_timeStepping)
	{
		// reset the time
		m_currentTimeStepping = 0.0f;

		// get a random angle between - angleStepping and + angleStepping
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> distibution(-m_angleStepping * 2.0f, 0);
		float angleModifier = distibution(gen);

		// Set our new rotation which the old rotation plus the angle modifier
		a_agent.m_movementInfo.m_rotation += angleModifier;

		// calculate the new target X and Y based on the new rotation
		float s = sinf(a_agent.m_movementInfo.m_rotation);
		float c = cosf(a_agent.m_movementInfo.m_rotation);
		m_targetPosition.x = (a_agent.m_movementInfo.m_position.x * c) - (a_agent.m_movementInfo.m_position.y * s);
		m_targetPosition.y = (a_agent.m_movementInfo.m_position.x * s) + (a_agent.m_movementInfo.m_position.y * c);
	}
		
	// Get the normal of the new target position
	Vector2 normal = Vector2Normalize(m_targetPosition);

	// Calculate the force to get there
	Vector2 force =  Vector2Subtract(Vector2Scale(normal, a_agent.m_movementInfo.m_maxSpeed), a_agent.m_movementInfo.m_velocity);
		
	// Cap the force
	force = Vector2Scale(force , a_agent.m_movementInfo.m_maxForce);

	// Apply the force to acceleration
	a_agent.m_movementInfo.m_acceleration = Vector2Add( force, a_agent.m_movementInfo.m_acceleration);
}
