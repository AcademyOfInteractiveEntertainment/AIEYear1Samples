#pragma once

#include "Behaviour.h"
#include <string>

// condition is also a behaviour so that it can work within a behaviour tree
class Condition : public Behaviour {
public:

	Condition() {}
	virtual ~Condition() {}

	virtual bool Test(Agent* agent) const = 0;

	virtual eBehaviourResult Execute(Agent* agent, float deltaTime) {
		if (Test(agent))
			return eBehaviourResult::SUCCESS;
		return eBehaviourResult::FAILURE;
	}
};

class NotCondition : public Condition {
public:

	NotCondition(const Condition* condition) : m_condition(condition) {}
	virtual ~NotCondition() {}

	virtual bool Test(Agent* agent) const {
		return !m_condition->Test(agent);
	}

private:

	const Condition* m_condition;
};