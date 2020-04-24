#ifndef WANDER_H
#define WANDER_H

//--------
//	Brief: A Wander behavior for an agent
//	Author: Elizabeth Rowlands
//	Date: 4/3/2015
//--------

#include "IBehavior.h"
#include <raylib.h>

class Wander : public IBehavior
{
public:
	Wander();
	virtual ~Wander();
	virtual void Update(float deltaTime, Agent& agent);
	inline virtual const char* GetBehaviorName() { return "Wander"; }
	
	// How much to change the angle by the choosing the next target
	float m_angleStepping;

	// How often to change the target position
	float m_timeStepping;

private:
	// Current target
	Vector2 m_targetPosition;
		
	// Current accumilation of time: is reset to 0 when it reaches m_timeStepping
	float m_currentTimeStepping;
};

#endif