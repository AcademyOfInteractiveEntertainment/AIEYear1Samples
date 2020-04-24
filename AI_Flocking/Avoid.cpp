#include "Avoid.h"
#include "Agent.h"
#include "Circle.h"


Avoid::Avoid()
{
	m_targetPosition = nullptr;
	
	m_maxSeeAhead = 100.0f;
	m_maxAvoidForce = 5.0f;

	m_circles = nullptr;
}

Avoid::~Avoid()
{

}

void Avoid::Update(float a_deltaTime, Agent& a_agent)
{
	// Get the distance between the target position and our position
	Vector2 distance = Vector2Subtract( *m_targetPosition , a_agent.m_movementInfo.m_position);

	// Declare and set to 0 incase magnitude is 0
	Vector2 normal = Vector2Normalize(distance);
		
	// Calculate the force that will be added this frame
	Vector2 force = Vector2Subtract(Vector2Scale( normal , a_agent.m_movementInfo.m_maxSpeed), a_agent.m_movementInfo.m_velocity);

	force = Vector2Scale(Vector2Normalize(force) , a_agent.m_movementInfo.m_maxForce);

	// set the force to the acceleration
	a_agent.m_movementInfo.m_acceleration = Vector2Add(force, a_agent.m_movementInfo.m_acceleration);

	// If m_circles hasnt been set then there is no data to calculations on
	if (m_circles == nullptr)
		return;

	// Get a normalized direction of the agent
	normal = Vector2Normalize(a_agent.m_movementInfo.m_velocity);

	// Calculate how far to look ahead based on the agents velocity
	float dynamicSeeAhead = Vector2Length(a_agent.m_movementInfo.m_velocity) / a_agent.m_movementInfo.m_maxSpeed;

	// Calculate the 2 positions to check at based on the dynamic see ahead value
	m_aheadPosition = Vector2Add(a_agent.m_movementInfo.m_position , Vector2Scale (normal , dynamicSeeAhead));

	// Ditto: this one uses half of the dynamic see ahead value
	m_aheadPosition2 = Vector2Add(a_agent.m_movementInfo.m_position , Vector2Scale( normal , dynamicSeeAhead * 0.5f));
	
	// The closest circle (obsticle)
	int mostThreateningIndex = -1;

	for (unsigned int i = 0; i < m_circles->size(); i++)
	{
		// For both of the ahead positions: see if its distance from the agent is less than the circle radius		
		if (Vector2Length(Vector2Subtract((*m_circles)[i]->m_position , m_aheadPosition)) <= (*m_circles)[i]->m_radius ||
			Vector2Length(Vector2Subtract((*m_circles)[i]->m_position , m_aheadPosition2)) <= (*m_circles)[i]->m_radius)
		{
			// The distance between the agent and the current most threatening circle (closest)
			Vector2 thisToIndex{0,0};
			if (mostThreateningIndex != -1)
			{
				thisToIndex = Vector2Subtract(a_agent.m_movementInfo.m_position , (*m_circles)[mostThreateningIndex]->m_position);
			}

			// The distance between the agent and the circle being checked in the current iteration
			Vector2 distanceAgent2Circle = Vector2Subtract(a_agent.m_movementInfo.m_position , (*m_circles)[i]->m_position);
			
			// if the distance of distanceAgent2Circle is less than the distance of the current closest circle || if the closest circle hasn't been set yet
			if (Vector2Length(distanceAgent2Circle) < Vector2Length(thisToIndex) || mostThreateningIndex == -1)
			{
				mostThreateningIndex = i;
			}
		}
	}

	// The force to apply to the agent to avoid the clostest obsticle
	Vector2 avoidanceForce = {0,0};

	// Check that there is a circle that we are going to collide with
	if (mostThreateningIndex != -1)
	{
		// The force is based off the distance between the agent and the closest circle
		avoidanceForce = Vector2Subtract(a_agent.m_movementInfo.m_position , (*m_circles)[mostThreateningIndex]->m_position);
		
		// Cap the force
		avoidanceForce = Vector2Scale(Vector2Normalize(avoidanceForce) , m_maxAvoidForce);
	}

	// Apply the force to the agents acceleration
	a_agent.m_movementInfo.m_acceleration = Vector2Add(avoidanceForce , a_agent.m_movementInfo.m_acceleration);
}