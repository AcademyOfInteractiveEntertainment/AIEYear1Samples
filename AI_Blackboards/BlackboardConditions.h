#pragma once
#include "Condition.h"

// condition that checks blackboard
class BlackboardBoolCondition : public Condition {
public:

	BlackboardBoolCondition(const char* entry) : m_entry(entry) {}
	virtual ~BlackboardBoolCondition() {}

	virtual bool Test(Agent* agent) const {
		bool value = false;
		agent->GetBlackboard().Get(m_entry, value);
		return value;
	}

protected:

	std::string m_entry;
};

// condition that checks blackboard
class BlackboardHasEntryCondition : public Condition {
public:

	BlackboardHasEntryCondition(const char* entry) : m_entry(entry) {}
	virtual ~BlackboardHasEntryCondition() {}

	virtual bool Test(Agent* agent) const {
		return agent->GetBlackboard().Contains(m_entry);
	}

protected:

	std::string m_entry;
};
