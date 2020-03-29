#pragma once
#include "Behaviour.h"
class FleeBehaviour :
	public Behaviour
{
public:
	FleeBehaviour() {};
	virtual ~FleeBehaviour() {};

	virtual Vector2 Update(Agent* agent, float deltaTime);
	void SetTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target;
	float m_maxSpeed = 50;
};

