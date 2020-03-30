#pragma once
#include "Behaviour.h"

class WanderBehaviour :
	public Behaviour
{
public:
	WanderBehaviour();
	virtual ~WanderBehaviour() {};

	virtual Vector2 Update(Agent* agent, float deltaTime);

	void Draw(Agent* agent);	// for debug only

private:
	Vector2 SetAngle(Vector2 vector, float value);

private:
	float m_circleDistance = 80;
	float m_circleRadius = 50;
	float m_wanderAngle = 0;

	const float m_angleChange = 50;

	/// DEBUG ONLY
private:
	Vector2 debug_cirleCenter;
	Vector2 debug_displacement;
	/// DEBUG ONLY
};

