#include "State.h"

Transition* State::GetTriggeredTransition(Agent* agent) {

	for (auto transition : m_transitions) {
		if (transition->HasTriggered(agent))
			return transition;
	}

	return nullptr;
}

eBehaviourResult FiniteStateMachine::Execute(Agent* agent, float deltaTime) {

	State* state = nullptr;
	agent->GetBlackboard().Get("currentState", &state);
	if (state != nullptr) {

		Transition* transition = state->GetTriggeredTransition(agent);

		if (transition != nullptr) {

			state->OnExit(agent);

			state = transition->GetTargetState();
			agent->GetBlackboard().Set("currentState", state);

			state->m_timer = 0;
			state->OnEnter(agent);
		}

		// accumulate time and update state
		state->m_timer += deltaTime;
		state->Update(agent, deltaTime);

		return eBehaviourResult::SUCCESS;
	}

	return eBehaviourResult::FAILURE;
}