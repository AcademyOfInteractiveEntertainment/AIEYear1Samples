#pragma once


class Blackboard;
class BlackboardQuestion;

class BlackboardExpert {
public:

	BlackboardExpert() {}
	virtual ~BlackboardExpert() {}

	virtual float EvaluateResponse(BlackboardQuestion* question, Blackboard* blackboard) = 0;

	virtual void Execute(BlackboardQuestion* question, Blackboard* blackboard) = 0;
};