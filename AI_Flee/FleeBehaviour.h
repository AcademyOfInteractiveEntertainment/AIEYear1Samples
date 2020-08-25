#pragma once
#include "Behaviour.h"
class FleeBehaviour :
	public Behaviour
{
public:
	FleeBehaviour() {};
	virtual ~FleeBehaviour() {};

	virtual bool Update(Agent* agent, float deltaTime);
	void SetDestination(Vector2 destination) { m_destination = destination; }

private:
	Vector2 m_destination;
	float m_fleeRadius = 100;
};

