#pragma once

#include "BlackboardAgent.h"
#include "State.h"
#include "BlackboardRespondBehaviour.h"
#include "SteeringBehaviour.h"

class Game
{
public:
	Game();
	virtual ~Game();

	bool Startup();
	void Shutdown();

	void Update(float deltaTime);
	void Draw();

protected:

	void ScreenWrap(float& x, float& y);
		
	BlackboardAgent m_entities[30];

	// shared state machine and wander force
	FiniteStateMachine m_fsm;
	WanderForce m_wander;

	// shared behaviour for responding to help requests
	BlackboardRespondBehaviour m_respondBehaviour;

	// timer for tracking when to request help (a hack for now)
	// to do this properly the behaviour of the entity's
	// would request help when it is hurt
	float m_someoneNeedsHelpTimer;

	// shared questions that get posted requesting help
	NeedHelpQuestion m_requireFiremanQuestion;
	NeedHelpQuestion m_requireMedicQuestion;

	// shared "level" blackboard for global state data
	Blackboard m_globalBlackboard;
};

