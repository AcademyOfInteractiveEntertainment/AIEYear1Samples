#include "WanderBehaviour.h"
#include <time.h>

WanderBehaviour::WanderBehaviour()
{
	srand(time(nullptr));
}

Vector2 WanderBehaviour::SetAngle(Vector2 vector, float value)
{
	float length = Vector2Length(vector);
	return { cosf(value) * length, sinf(value) * length };
}

bool WanderBehaviour::Update(Agent* agent, float deltaTime)
{	
	Vector2 velocity = agent->GetVelocity();
	if (Vector2Length(velocity) == 0)
	{
		velocity = { 0, -1 };

	}
	// The code to calculate the circle center:
	// m_circleDistance from the current agent position, in the same direction as the current velocity
	Vector2 circleCenter = Vector2Scale(Vector2Normalize(velocity), m_circleDistance);

	Vector2 displacement = { 0, -1 };
	displacement = Vector2Scale(displacement, m_circleRadius);
	//
	// Randomly change the vector direction
	// by making it change its current angle
	displacement = SetAngle(displacement, m_wanderAngle);

	//
	// Change wanderAngle just a bit, so it
	// won't have the same value in the
	// next game frame.	
	m_wanderAngle += (rand() % (int)m_angleChange) - m_angleChange * .5;

	Vector2 wanderForce = Vector2Add(circleCenter, displacement);

	/// DEBUG ONLY
	debug_cirleCenter = Vector2Add(agent->GetPosition(), circleCenter);
	debug_displacement = displacement;
	/// DEBUG ONLY

	agent->AddForce(wanderForce);
	return true;
}

/// DEBUG ONLY
void WanderBehaviour::Draw(Agent* agent)
{
	DrawCircle(debug_cirleCenter.x, debug_cirleCenter.y, m_circleRadius, BLUE);
	DrawLine(debug_cirleCenter.x, debug_cirleCenter.y, 
		debug_cirleCenter.x + debug_displacement.x, debug_cirleCenter.y + debug_displacement.y, MAGENTA);
}
/// DEBUG ONLY