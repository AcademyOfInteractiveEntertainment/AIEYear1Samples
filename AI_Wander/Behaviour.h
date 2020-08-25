#pragma once
#include "Agent.h"

class Behavior
{
public:

	// empty constructors and destructors for base class
	Behavior() {}
	virtual ~Behavior() {}

	// pure virtual function for executing the behaviour
	virtual bool Update(Agent* agent, float deltaTime) = 0;
};
