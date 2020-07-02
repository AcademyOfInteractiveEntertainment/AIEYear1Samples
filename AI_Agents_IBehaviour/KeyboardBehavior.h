#ifndef KEYBOARDBEHAVIOR_H
#define KEYBOARDBEHAVIOR_H

#include "IBehavior.h"

//--------
//	Breif: Takes input from the keyboard and moves the agent
//	Author: Elizabeth Rowlands
//	Date : 11/3/2015
//--------

class KeyboardBehavior : public IBehavior
{
public:
	KeyboardBehavior();
	~KeyboardBehavior();
	void Update(float deltaTime, MovementInfo& movementInfo);
};

#endif