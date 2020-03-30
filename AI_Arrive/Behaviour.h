#pragma once
#include "Agent.h"

class Behaviour
{
public:

	// empty constructors and destructors for base class
	Behaviour() {}
	virtual ~Behaviour() {}

	// pure virtual function for executing the behaviour
	virtual Vector2 Update(Agent* agent, float deltaTime) = 0;
};
