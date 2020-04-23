#include "BlackboardRespondBehaviour.h"
#include "BlackboardAgent.h"

// go through questions and respond to those we think are valid
eBehaviourResult BlackboardRespondBehaviour::Execute(Agent* agent, float deltaTime) {

	auto& questions = m_blackboard->GetQuestions();

	int entityClass = eEntityClass::CIVILIAN;
	agent->GetBlackboard().Get("class", entityClass);

	for (auto& question : questions) {

		// can we respond?
		int type = question->GetType();

		if ((type == eBlackboardQuestionType::REQUIRE_MEDIC &&
			entityClass == eEntityClass::MEDIC) ||
			(type == eBlackboardQuestionType::REQUIRE_FIREMAN &&
				entityClass == eEntityClass::FIREMAN))
			question->AddExpert((BlackboardAgent*)agent);
	}

	return eBehaviourResult::SUCCESS;
}