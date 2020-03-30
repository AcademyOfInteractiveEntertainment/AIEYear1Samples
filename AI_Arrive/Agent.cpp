#include "Agent.h"
#include "Behaviour.h"
#include <algorithm>

Agent::Agent()
{

}

Agent::~Agent()
{

}

Vector2 Agent::Truncate(Vector2 v, float max)
{
	float i = max / Vector2Length(v);
	i = i < 1.0 ? i : 1.0;
	return Vector2Scale(v, i);
}

// Update the agent and its behaviours
void Agent::Update(float deltaTime)
{
	// Force is equal to zero
	// For each Behaviour in Behaviour list
	//	 Call the Behaviour’s Update functionand add the returned value to Force
	// Add Force multiplied by delta time to Velocity
	// Add Velocity multiplied by delta time to Position
	
	for (int i = 0; i < m_behaviourList.size(); i++)
	{
		Vector2 force = m_behaviourList[i]->Update(this, deltaTime);

		// If (velocity + steering) equals zero, then there is no movement
		m_velocity = Truncate((Vector2Add(m_velocity, force)), m_maxSpeed);
		m_position = (Vector2Add(m_position, Vector2Scale(m_velocity, deltaTime)));
	}

}

// Draw the agent
void Agent::Draw()
{
	DrawRectangle(m_position.x, m_position.y, 10, 10, RED);
}

// Add a behaviour to the agent
void Agent::AddBehaviour(Behaviour* behaviour)
{
	m_behaviourList.push_back(behaviour);
}