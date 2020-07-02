#ifndef AGENT_H
#define AGENT_H

#include "raymath.h"

//--------
//	Breif: A class that can be moved around by using steering behaviours
//	Author: Elizabeth Rowlands
//	Date : 4/3/2015
//--------
class IBehavior;

struct MovementInfo
{
	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_acceleration;

	float m_maxSpeed;
	float m_maxForce;

	float m_rotation;
	float m_rotationDampening;
};

class Agent
{
public:
	Agent();
	Agent(float positionX, float positionY);
	virtual ~Agent();

	// Getters
	inline Vector2 GetPosition() { return m_movementInfo.m_position; }
	inline IBehavior* GetBehaviour() { return m_currentBehavior; }

	// Setters
	inline void SetBehavior(IBehavior *behavior) 
	{
		m_currentBehavior = behavior; 
	}

	void Update(float deltaTime);

	MovementInfo m_movementInfo;

private:
	void Init(float positionX, float positionY);
	
	IBehavior *m_currentBehavior;
};

#endif