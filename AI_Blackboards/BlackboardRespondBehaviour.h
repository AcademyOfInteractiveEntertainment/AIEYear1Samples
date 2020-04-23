#pragma once
#include "Behaviour.h"
#include "Blackboard.h"
#include "Agent.h"

// behaviour that responds to questions this entity can answer
class BlackboardRespondBehaviour : public Behaviour {
public:

	BlackboardRespondBehaviour(Blackboard* blackboard) : m_blackboard(blackboard) {}
	virtual ~BlackboardRespondBehaviour() {}

	virtual eBehaviourResult Execute(Agent* agent, float deltaTime);

protected:

	Blackboard* m_blackboard;
};