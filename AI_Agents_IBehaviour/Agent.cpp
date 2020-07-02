#include "Agent.h"
#include "IBehavior.h"

#define _USE_MATH_DEFINES
#include <math.h>

Agent::Agent()
{
	Init(0.0f, 0.0f);
}

Agent::Agent(float a_positionX, float a_positionY)
{
	Init(a_positionX, a_positionY);
}

Agent::~Agent()
{
	
}

void Agent::Update(float a_deltaTime)
{
	if (m_currentBehavior != nullptr)
	{
		m_currentBehavior->Update(a_deltaTime, m_movementInfo);
	}

	m_movementInfo.m_velocity.x += m_movementInfo.m_acceleration.x;
	m_movementInfo.m_velocity.y += m_movementInfo.m_acceleration.y;
	if (m_movementInfo.m_velocity.x > m_movementInfo.m_maxSpeed)
	{
		m_movementInfo.m_velocity.x = m_movementInfo.m_maxSpeed;
	}
	else if (m_movementInfo.m_velocity.x < -m_movementInfo.m_maxSpeed)
	{
		m_movementInfo.m_velocity.x < -m_movementInfo.m_maxSpeed;
	}
	if (m_movementInfo.m_velocity.y > m_movementInfo.m_maxSpeed)
	{
		m_movementInfo.m_velocity.y = m_movementInfo.m_maxSpeed;
	}
	else if (m_movementInfo.m_velocity.y < -m_movementInfo.m_maxSpeed)
	{
		m_movementInfo.m_velocity.y < -m_movementInfo.m_maxSpeed;
	}
	
	m_movementInfo.m_rotation = atan2(m_movementInfo.m_velocity.y, m_movementInfo.m_velocity.x) + M_PI / 2;

	m_movementInfo.m_acceleration.x = 0.0f;
	m_movementInfo.m_acceleration.y = 0.0f;

	m_movementInfo.m_position.x += m_movementInfo.m_velocity.x;
	m_movementInfo.m_position.y += m_movementInfo.m_velocity.y;
}

void Agent::Init(float a_positionX, float a_positionY)
{
	m_movementInfo.m_position.x = a_positionX;
	m_movementInfo.m_position.y = a_positionY;
	m_movementInfo.m_velocity.x = 0.0f;
	m_movementInfo.m_velocity.y = 0.0f;
	m_movementInfo.m_acceleration.x = 0.0f;
	m_movementInfo.m_acceleration.y = 0.0f;
	m_movementInfo.m_maxSpeed = 4.0f;
	m_movementInfo.m_maxForce = 0.1f;
	m_movementInfo.m_rotation = 0.0f;
	m_movementInfo.m_rotationDampening = 0.05f;
	m_currentBehavior = nullptr;
}