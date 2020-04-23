#pragma once
#include "raymath.h"
#include <vector>
#include "Blackboard.h"

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
	void SetPosition(float x, float y) { m_position.x = x; m_position.y = y; }

	Vector2 GetPosition() { return m_position; }
	void GetPosition(float* x, float* y) { *x = m_position.x; *y = m_position.y; }
	void Translate(float x, float y) { m_position.x += x; m_position.y += y; }

	Blackboard& GetBlackboard() { return m_blackboard; }

private:
	Vector2 Truncate(Vector2 v, float max);

protected:
	std::vector<Behaviour*> m_behaviourList;
	Blackboard m_blackboard;

	Vector2 m_position = { 0, 0 };
};

