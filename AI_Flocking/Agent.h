#ifndef AGENT_H
#define AGENT_H

//--------
//	Breif: A class that can be moved around by using steering behaviours
//	Author: Elizabeth Rowlands
//	Date : 4/3/2015
//--------

#include <vector>
#include <raylib.h>
#include <raymath.h>

class Behavior;

// Container for position, movement, and rotation related data
struct MovementInfo
{
	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_acceleration;
		
	float m_maxSpeed;
	float m_maxForce;

	float m_rotation;
	float m_rotationDampening;
};

class Agent
{
public:
	Agent();
	Agent(Vector2 position);
	virtual ~Agent();
		
	void Update(float deltaTime);
	void Reset();

	void AddBehavior(Behavior* behavior) { m_behaviors.push_back(behavior); }

	MovementInfo m_movementInfo;

	static std::vector<Agent*>* agents;
private:
	// Function for constructors to call
	void Init(Vector2 position);
	// Makes sure the agent doesnt run into any other agents
	void avoidAgents();
	// Makes sure the agent doesnt go off of the screen
	void avoidScreenBounds();

	// List of behaviors that will get called during every update
	std::vector<Behavior*> m_behaviors;

	// Position to reset to if the reset function gets called
	Vector2 m_resetPosition;
};

#endif