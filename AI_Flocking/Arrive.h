#ifndef ARRIVE_H
#define ARRIVE_H

//--------
//	Brief: An Arrive behavior for an agent
//	Author: Elizabeth Rowlands
//	Date: 4/3/2015
//--------

#include "Behavior.h"
#include <raylib.h>

class Arrive : public Behavior
{
public:
	Arrive();
	virtual ~Arrive();
	virtual void Update(float deltaTime, Agent& agent);
	inline virtual const char* GetBehaviorName() { return "Arrive"; }

	Vector2* m_targetPosition;
	float m_distance;
};

#endif