#pragma once
#include "Agent.h"

enum class eBehaviourResult {
	SUCCESS,
	FAILURE,
	RUNNING
};

class Behaviour
{
public:

	// empty constructors and destructors for base class
	Behaviour() {}
	virtual ~Behaviour() {}

	// pure virtual function for executing the behaviour
	virtual eBehaviourResult Execute(Agent* agent, float deltaTime) = 0;
};
