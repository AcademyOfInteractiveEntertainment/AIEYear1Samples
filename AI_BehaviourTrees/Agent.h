#pragma once
#include "raymath.h"
#include <list>

class Behaviour;

class Agent
{
public:
	Agent(float x, float y);
	virtual ~Agent();

	// Update the agent and its behaviours
	virtual void Update(float deltaTime);

	// Draw the agent
	virtual void Draw();

	void SetAttack(bool state) {m_bAttack = state;}
	
protected:
	Behaviour* m_pBehaviourTree;
	bool m_bAttack;

public:
	float m_maxSpeed;

	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_position;
};
