#pragma once

#include <vector>

class Blackboard;
class BlackboardExpert;
class Agent;


enum eBlackboardQuestionType : int {
	REQUIRE_MEDIC,
	REQUIRE_FIREMAN,
};

class BlackboardQuestion {
public:

	BlackboardQuestion(int id) : m_id(id) {};
	virtual ~BlackboardQuestion() {}

	int GetType() const { return m_id; }

	void AddExpert(BlackboardExpert* expert) { m_experts.push_back(expert); }

	void ClearExperts() { m_experts.clear(); }

protected:

	friend class Blackboard;

	bool Arbitrate(Blackboard* blackboard);

	int	m_id;
	std::vector<BlackboardExpert*>	m_experts;
};


// a question that gets posted to the blackboard requesting help
// this could be done better
class NeedHelpQuestion : public BlackboardQuestion {
public:
	NeedHelpQuestion(int type) : BlackboardQuestion(type) {}
	virtual ~NeedHelpQuestion() {}

	Agent* needsHelp;
};