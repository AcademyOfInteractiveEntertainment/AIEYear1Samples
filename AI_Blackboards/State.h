#pragma once

#include "Behaviour.h"
#include "Condition.h"
#include <vector>

class State;

class Transition {
public:

	Transition(State* target, Condition* condition) : m_target(target), m_condition(condition) {}
	~Transition() {}

	State* GetTargetState() { return m_target; }

	bool HasTriggered(Agent* agent) { return m_condition->Test(agent); }

private:

	State*		m_target;
	Condition*	m_condition;
};

// abstract class
class State {

	friend class FiniteStateMachine;

public:

	State() : m_timer(0) {}
	virtual ~State() {}

	// pure virtual
	virtual void Update(Agent* agent, float deltaTime) = 0;

	// triggers for enter / exit
	virtual void OnEnter(Agent* agent) {}
	virtual void OnExit(Agent* agent) {}

	void AddTransition(Transition* transition) {
		m_transitions.push_back(transition);
	}

	Transition*	GetTriggeredTransition(Agent* agent);

	const float* GetTimerPtr() const { return &m_timer; }

	float GetTimer() const { return m_timer; }

protected:

	float	m_timer;
	std::vector<Transition*>	m_transitions;
};

class FiniteStateMachine : public Behaviour {
public:

	FiniteStateMachine() {}

	virtual ~FiniteStateMachine() {
		for (auto state : m_states)
			delete state;
		for (auto t : m_transitions)
			delete t;
		for (auto c : m_conditions)
			delete c;
	}

	// add components, takes ownership
	State* AddState(State* state) { m_states.push_back(state); return state; }
	Transition* AddTransition(Transition* transition) {	m_transitions.push_back(transition); return transition;	}
	Condition* AddCondition(Condition* condition) { m_conditions.push_back(condition); return condition; }

	virtual eBehaviourResult Execute(Agent* agent, float deltaTime);

protected:

	std::vector<State*> m_states;
	std::vector<Transition*> m_transitions;
	std::vector<Condition*> m_conditions;
};