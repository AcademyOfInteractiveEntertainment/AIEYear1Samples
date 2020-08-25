#pragma once
#include "Behaviour.h"
class ArriveBehaviour :
	public Behaviour
{
public:
	ArriveBehaviour() {};
	virtual ~ArriveBehaviour() {};

	virtual bool Update(Agent* agent, float deltaTime);
	void SetDestination(Vector2 destination) { m_destination = destination; }

private:
	Vector2 m_destination;
	float m_slowingRadius = 100;
};

