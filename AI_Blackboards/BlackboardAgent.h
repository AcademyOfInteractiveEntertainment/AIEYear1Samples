#pragma once
#include "Agent.h"
#include "State.h"
#include "BlackboardExpert.h"

enum eEntityClass : int {
	CIVILIAN = 0,
	MEDIC,
	FIREMAN,
};


class BlackboardAgent : public Agent, public BlackboardExpert
{
public:
	BlackboardAgent() {}
	virtual ~BlackboardAgent() {}

	// blackboard methods
	virtual float EvaluateResponse(BlackboardQuestion* question, Blackboard* blackboard);
	virtual void Execute(BlackboardQuestion* question, Blackboard* blackboard);
};

