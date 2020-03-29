#pragma once
#include "Behaviour.h"
class KeyboardBehaviour :
	public Behaviour
{
public:
	KeyboardBehaviour() {};
	virtual ~KeyboardBehaviour() {};

	virtual Vector2 Update(Agent* agent, float deltaTime);

private:
	float m_speedIncrement = 50.0f;
};

