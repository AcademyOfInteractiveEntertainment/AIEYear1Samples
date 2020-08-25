#ifndef PURSUE_H
#define PURSUE_H
#include "Behavior.h"
#include <raylib.h>

class Pursue :	public Behavior
{
public:
	Pursue();
	~Pursue();
	void Update(float deltaTime, Agent& agent);
	inline virtual const char* GetBehaviorName() { return "Pursue"; }

	Vector2* m_targetPosition;
	Vector2* m_targetVelocity;
};

#endif