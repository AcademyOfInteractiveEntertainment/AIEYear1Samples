#pragma once
#include "raymath.h"
#include <vector>

class Behaviour;

class Agent
{
public:
	Agent();
	virtual ~Agent();

	// Update the agent and its behaviours
	virtual void Update(float deltaTime);

	// Draw the agent
	virtual void Draw();

	// Add a behaviour to the agent
	void AddBehaviour(Behaviour* behaviour);

	// Movement functions
	void SetPosition(Vector2 position) { m_position = position; }
	Vector2 GetPosition() { return m_position; }

	void SetVelocity(Vector2 velocity) { m_velocity = velocity; }
	Vector2 GetVelocity() { return m_velocity; }

	void SetMaxSpeed(float speed) { m_maxSpeed = speed; }
	float GetMaxSpeed() { return m_maxSpeed; }

private:
	Vector2 Truncate(Vector2 v, float max);

protected:
	std::vector<Behaviour*> m_behaviourList;

	Vector2 m_position = { 0, 0 };
	Vector2 m_velocity = { 0, 0 };
	float m_maxSpeed = 100;
};

