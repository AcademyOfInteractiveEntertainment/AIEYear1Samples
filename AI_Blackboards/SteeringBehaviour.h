#pragma once

#include "State.h"

class Agent;

// could be replaced with a vector2
struct Force {
	float x, y;
};

struct WanderData {
	float circleDistance = 80;
	float circleRadius = 50;
	float wanderAngle = 0;
	float angleChange = 50;
};

// abstract class
class SteeringForce {
public:

	SteeringForce() {}
	virtual ~SteeringForce() {}

	// pure virtual function
	virtual Force GetForce(Agent* agent) const = 0;
};

// weighted steering force
struct WeightedForce {
	SteeringForce* force;
	float weight;
};

// steering behaviour
class SteeringBehaviour : public Behaviour {
public:

	SteeringBehaviour() {}
	virtual ~SteeringBehaviour() {}

	void AddForce(SteeringForce* force, float weight = 1.0f) {
		WeightedForce wf = { force, weight };
		m_forces.push_back(wf);
	}

	void SetWeightForForce(SteeringForce* force, float weight) {
		for (auto& wf : m_forces) {
			if (wf.force == force)
				wf.weight = weight;
		}
	}

	virtual eBehaviourResult Execute(Agent* agent, float deltaTime);

protected:

	std::vector<WeightedForce>	m_forces;
};

// steering behaviour state for a FSM
class SteeringState : public State {
public:

	SteeringState() {}
	virtual ~SteeringState() {}

	void AddForce(SteeringForce* force, float weight = 1.0f) {
		WeightedForce wf = { force, weight };
		m_forces.push_back(wf);
	}

	void SetWeightForForce(SteeringForce* force, float weight) {
		for (auto& wf : m_forces) {
			if (wf.force == force)
				wf.weight = weight;
		}
	}

	virtual void Update(Agent* agent, float deltaTime);

protected:

	std::vector<WeightedForce>	m_forces;
};

class WanderForce : public SteeringForce {
public:

	WanderForce() {}
	virtual ~WanderForce() {}

	virtual Force GetForce(Agent* gameObject) const;


private:
	Vector2 SetAngle(Vector2 vector, float value) const;
};
