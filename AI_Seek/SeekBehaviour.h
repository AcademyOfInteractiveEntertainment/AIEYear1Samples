#pragma once
#include "Behaviour.h"
class SeekBehaviour :
	public Behaviour
{
public:
	SeekBehaviour() {};
	virtual ~SeekBehaviour() {};

	virtual Vector2 Update(Agent* agent, float deltaTime);
	void SetTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target;
	float m_maxSpeed = 10;
};

