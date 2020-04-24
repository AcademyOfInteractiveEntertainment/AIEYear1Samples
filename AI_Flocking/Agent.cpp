#include "Agent.h"
#define _USE_MATH_DEFINES

#include "IBehavior.h"

#include <iostream>

std::vector<Agent*>* Agent::agents;

Agent::Agent()
{
	Init(Vector2());
}

Agent::Agent(Vector2 a_position)
{
	Init(a_position);
}

Agent::~Agent()
{
	
}

void Agent::Update(float a_deltaTime)
{
	//--------------------------------
	// SENSE
	//--------------------------------
	// Avoid other agents
	avoidAgents();
	// Avoid the edge of the screen
	//avoidScreenBounds();
	
	//--------------------------------
	// THINK
	//--------------------------------
	// Update all behaviors
	for (auto behavior : m_behaviors)
	{
		behavior->Update(a_deltaTime, *this);
	}

	//--------------------------------
	// ACT
	//--------------------------------
	// Update the velocity with the current acceleration
	m_movementInfo.m_velocity = Vector2Add(m_movementInfo.m_velocity ,m_movementInfo.m_acceleration);
	
	m_movementInfo.m_velocity = Vector2Scale(m_movementInfo.m_velocity , 0.9f);

	// Cap the velocity
	//if (m_movementInfo.m_velocity.x != 0.0f && m_movementInfo.m_velocity.y != 0.0f)
	//{
	//	m_movementInfo.m_velocity = glm::normalize(m_movementInfo.m_velocity) * m_movementInfo.m_maxSpeed;
	//}
	
	// Set rotation
	m_movementInfo.m_rotation = atan2(m_movementInfo.m_velocity.y, m_movementInfo.m_velocity.x);

	// Reset the acceleration for the next frame
	m_movementInfo.m_acceleration = Vector2();
	
	// Add the velocity to the position
	m_movementInfo.m_position = Vector2Add(m_movementInfo.m_velocity, m_movementInfo.m_position);
}

void Agent::Reset()
{
	// Move the agent back to where they started
	m_movementInfo.m_position = m_resetPosition;
	
	// Zero out the velocity so they dont start moving after being reset
	m_movementInfo.m_velocity = Vector2();
	
	// Ditto
	m_movementInfo.m_acceleration = Vector2();	
}

void Agent::Init(Vector2 a_position)
{
	m_resetPosition = a_position;
	
	m_movementInfo.m_position = m_resetPosition;
	m_movementInfo.m_velocity = Vector2();
	m_movementInfo.m_acceleration = Vector2();
	
	m_movementInfo.m_maxSpeed = 2.0f;
	m_movementInfo.m_maxForce = 0.5f;
	
	m_movementInfo.m_rotation = 0.0f;
	m_movementInfo.m_rotationDampening = 0.15f;
}

void Agent::avoidAgents()
{
	// = Game1::GetAgents();
	
	for (auto agent : *agents)
	{
		if (agent != this)
		{
			Vector2 d(Vector2Subtract(agent->m_movementInfo.m_position , m_movementInfo.m_position));
			float distanceSquared = Vector2Length(d) * Vector2Length(d);

			float radius = 50;
			float radiusSquared = radius * radius;

			if (distanceSquared < radiusSquared && distanceSquared != 0)
			{
				float distance = sqrt(distanceSquared);
				Vector2 collisionNormal = Vector2Scale(d , 1.0f / distance);
				//std::cout << collisionNormal.x << " " << collisionNormal.y << std::endl;
				m_movementInfo.m_position = Vector2Subtract(m_movementInfo.m_position, collisionNormal);
				agent->m_movementInfo.m_position = Vector2Add( agent->m_movementInfo.m_position, collisionNormal);
			}

			//if (abs() < magicNumberRadius)
			//{
			//	agent->m_movementInfo.m_acceleration -= magicNumberRadius;
			//	m_movementInfo.m_acceleration += magicNumberRadius;
			//}
		}
	}
}

void Agent::avoidScreenBounds()
{
	static unsigned int screenWidth		= 800;
	static unsigned int screenHeight	= 600;

	if (m_movementInfo.m_position.x < 0)
		m_movementInfo.m_position.x = 0;
	if (m_movementInfo.m_position.x > screenWidth)
		m_movementInfo.m_position.x = screenWidth;
	if (m_movementInfo.m_position.y < 0)
		m_movementInfo.m_position.y = 0;
	if (m_movementInfo.m_position.y > screenHeight)
		m_movementInfo.m_position.y = screenHeight;
}