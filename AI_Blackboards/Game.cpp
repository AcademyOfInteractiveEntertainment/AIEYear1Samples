#include "Game.h"
#include "BlackboardQuestion.h"
#include "BlackboardState.h"
#include "SteeringBehaviour.h"
#include "Condition.h"
#include "BlackboardConditions.h"
#include "BlackboardAgent.h"
#include <time.h>

Game::Game()
	: m_requireFiremanQuestion(eBlackboardQuestionType::REQUIRE_FIREMAN),
	m_requireMedicQuestion(eBlackboardQuestionType::REQUIRE_MEDIC),
	m_respondBehaviour(&m_globalBlackboard) {

}

Game::~Game() {

}

bool Game::Startup() {
	srand(time(nullptr));

	// setup the behaviour of entities

	auto wanderState = new SteeringState();
	wanderState->AddForce(&m_wander);

	auto idleState = new IdleState();
	auto helpState = new HelpEntityState();

	// conditions for triggering transitions
	auto needHelpCondition = new BlackboardBoolCondition("requireHelp");
	auto helpingCondition = new BlackboardHasEntryCondition("target");
	auto dontNeedHelpCondition = new NotCondition(needHelpCondition);
	auto notHelpingCondition = new NotCondition(helpingCondition);

	// transitions between states
	auto toHelpingTransition = new Transition(helpState, helpingCondition);
	auto toIdleTransition = new Transition(idleState, needHelpCondition);
	auto toIdleFromHelpingTransition = new Transition(idleState, notHelpingCondition);
	auto toWanderTransition = new Transition(wanderState, dontNeedHelpCondition);

	wanderState->AddTransition(toIdleTransition);
	wanderState->AddTransition(toHelpingTransition);
	idleState->AddTransition(toWanderTransition);
	helpState->AddTransition(toIdleFromHelpingTransition);

	// store in FSM for memory cleanup
	m_fsm.AddState(idleState);
	m_fsm.AddState(helpState);
	m_fsm.AddState(wanderState);

	m_fsm.AddTransition(toIdleTransition);
	m_fsm.AddTransition(toIdleFromHelpingTransition);
	m_fsm.AddTransition(toHelpingTransition);
	m_fsm.AddTransition(toWanderTransition);

	m_fsm.AddCondition(helpingCondition);
	m_fsm.AddCondition(needHelpCondition);
	m_fsm.AddCondition(dontNeedHelpCondition);
	m_fsm.AddCondition(notHelpingCondition);

	m_someoneNeedsHelpTimer = 3;

	// setup entities
	for (auto& go : m_entities) {

		auto& blackboard = go.GetBlackboard();

		Vector2* v = new Vector2();
		v->x = 0;
		v->y = 0;
		blackboard.Set("velocity", v, true);

		WanderData* wd = new WanderData();

		wd->circleDistance = 80;
		wd->circleRadius = 50;
		wd->wanderAngle = 0;
		wd->angleChange = 50;
		blackboard.Set("wanderData", wd, true);

		blackboard.Set("speed", 75.f);
		blackboard.Set("maxForce", 300.f);
		blackboard.Set("maxVelocity", 75.f);

		blackboard.Set("currentState", wanderState);

		// store the class the entity belongs to
		// fireman / medic / civilian
		blackboard.Set("class", rand() % 3);
		blackboard.Set("requireHelp", false);

		go.AddBehaviour(&m_fsm);
		go.AddBehaviour(&m_respondBehaviour);

		go.SetPosition(float(rand() % GetScreenWidth()),
			float(rand() % GetScreenHeight()));
	}

	return true;
}

void Game::Shutdown() {

}

void Game::Update(float deltaTime) {

	// post question every few seconds
	// this is a hack: usually an entity's behaviour would
	// make it ask for help
	m_someoneNeedsHelpTimer -= deltaTime;
	if (m_someoneNeedsHelpTimer <= 0) {

		// post a question and pick a random that needs help
		auto go = &m_entities[rand() % 30];
		go->GetBlackboard().Set("requireHelp", true);

		if (rand() % 2 == 0) {
			m_requireFiremanQuestion.needsHelp = go;
			m_globalBlackboard.AddQuestion(&m_requireFiremanQuestion);
		}
		else {
			m_requireMedicQuestion.needsHelp = go;
			m_globalBlackboard.AddQuestion(&m_requireMedicQuestion);
		}

		// reset timer
		m_someoneNeedsHelpTimer = 3;
	}

	// update behaviours (will also respond to questions)
	for (auto& go : m_entities)
		go.Update(deltaTime);

	// arbitrate questions
	m_globalBlackboard.RunArbitration();
}

void Game::ScreenWrap(float& x, float& y) {
	// wrap position around the screen
	x = fmod(x, (float)GetScreenWidth());
	if (x < 0)
		x += GetScreenWidth();
	y = fmod(y, (float)GetScreenHeight());
	if (y < 0)
		y += GetScreenHeight();
}

void Game::Draw() {

	BeginDrawing();

	ClearBackground(RAYWHITE);

	int entityClass = eEntityClass::CIVILIAN;
	float x, y;

	// draw entities
	for (auto& go : m_entities) {

		go.GetBlackboard().Get("class", entityClass);

		Color color = BLUE;
		// different colour based on class
		switch (entityClass) {
			case eEntityClass::MEDIC:	
				color = PURPLE;
				break;
			case eEntityClass::FIREMAN:	
				color = GREEN;
				break;
			default:	
				color = BLUE;
				break;
		};

		go.GetPosition(&x, &y);
		ScreenWrap(x, y);
		go.SetPosition(x, y);

		DrawCircle(x, y, 10, color);

		// draw red circle around entities needing help
		bool requireHelp = false;
		go.GetBlackboard().Get("requireHelp", requireHelp);
		if (requireHelp) {			
			DrawCircle(x, y, 20, RED);
		}
	}

	// output some text
	
	DrawText("Medics", 0, 64, 12, PURPLE);
	DrawText("Firemen", 0, 32, 12, GREEN);
	DrawText("Civilians", 0, 0, 12, BLUE);

	EndDrawing();
}
