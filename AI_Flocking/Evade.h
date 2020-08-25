#ifndef EVADE_H
#define EVADE_H
#include "Behavior.h"
#include <raylib.h>

class Evade : public Behavior
{
public:
	Evade();
	~Evade();

	void Update(float deltaTime, Agent& agent);
	inline virtual const char* GetBehaviorName() { return "Evade"; }

	// The X and Y position to use in calculations for the target to evade from
	Vector2* m_targetPosition;
	Vector2* m_targetVelocity;
};

#endif