#pragma once
#include "State.h"

// state does nothing
class IdleState : public State {
public:

	IdleState() {}
	virtual ~IdleState() {}
	virtual void Update(Agent* agent, float deltaTime) {}
};

// game object moves towards its target
// when it gets there it marks blackboards as success
class HelpEntityState : public State {
public:

	HelpEntityState() {}
	virtual ~HelpEntityState() {}
	virtual void Update(Agent* agent, float deltaTime);
};