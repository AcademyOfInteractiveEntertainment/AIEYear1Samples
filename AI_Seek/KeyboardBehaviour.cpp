#include "KeyboardBehaviour.h"

Vector2 KeyboardBehaviour::Update(Agent* agent, float deltaTime)
{
	Vector2 force = { 0, 0 };

	if (IsKeyDown(KEY_UP))
		force.y = -m_speedIncrement;
	if (IsKeyDown(KEY_DOWN))
		force.y = m_speedIncrement;
	if (IsKeyDown(KEY_LEFT))
		force.x = -m_speedIncrement;
	if (IsKeyDown(KEY_RIGHT))
		force.x = m_speedIncrement;

	return force;
}

