#ifndef SEEK_H
#define SEEK_H

//--------
//	Brief: A Seek behavior for an agent
//	Author: Elizabeth Rowlands
//	Date: 4/3/2015
//--------

#include "Behavior.h"
#include <raylib.h>

class Seek : public Behavior
{
public:
	Seek();
	virtual ~Seek();
	virtual void Update(float deltaTime, Agent& agent);
	inline virtual const char* GetBehaviorName() { return "Seek"; }

	// X and Y position to seek towards
	Vector2* m_targetPosition;
};

#endif