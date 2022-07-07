#include "Agent.h"
#include "Behaviour.h"
#include "Behaviours.h"

Agent::Agent(float x, float y) : m_pBehaviourTree(nullptr), m_bAttack(false)
{
	m_maxSpeed = 100;
	m_position = { x, y };
		
	// looks hideous, but basically builds the tree without using temp variables
	m_pBehaviourTree = 
		(new Selector())->add( 
			(new Sequence())->add(
				new MouseCloseCondition())->add(
				new AttackAction()))->add(
			(new Sequence())->add(
				new StopAttackAction())->add(
				new SeekAction()) );
				
}

Agent::~Agent()
{
	if(m_pBehaviourTree != nullptr)
		delete m_pBehaviourTree;
}

// Update the agent and its behaviours
void Agent::Update(float deltaTime)
{
	
	if(m_pBehaviourTree != nullptr)
		m_pBehaviourTree->tick(this, deltaTime);
		
	m_velocity.x += m_acceleration.x;
	m_velocity.y += m_acceleration.y;

	if (m_velocity.x > m_maxSpeed) {
		m_velocity.x = m_maxSpeed;
	}
	else if (m_velocity.x < -m_maxSpeed) {
		m_velocity.x < -m_maxSpeed;
	}
	if (m_velocity.y > m_maxSpeed) {
		m_velocity.y = m_maxSpeed;
	}
	else if (m_velocity.y < -m_maxSpeed) {
		m_velocity.y < -m_maxSpeed;
	}

	m_acceleration.x = 0;
	m_acceleration.y = 0;

	m_position.x += m_velocity.x * deltaTime;
	m_position.y += m_velocity.y * deltaTime;

}

void Agent::Draw()
{
	if(!m_bAttack)
		DrawRectangle(m_position.x, m_position.y, 10, 10, RED);		
	else
		DrawRectangle(m_position.x, m_position.y, 10, 10, GREEN);
}
