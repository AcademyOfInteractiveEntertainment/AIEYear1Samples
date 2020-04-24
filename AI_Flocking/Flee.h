#ifndef FLEE_H
#define FLEE_H

//--------
//	Brief: A Flee behavior for an agent
//	Author: Elizabeth Rowlands
//	Date: 4/3/2015
//--------

#include "IBehavior.h"
#include <raylib.h>

class Flee : public IBehavior
{
public:
	Flee();
	virtual ~Flee();
	virtual void Update(float deltaTime, Agent& agent);
	inline virtual const char* GetBehaviorName() { return "Flee"; }

	// X and Y position to flee from
	Vector2 *m_targetPosition;
};

#endif