#pragma once
namespace pathfinding
{
	class Agent;

	// abstract base class for all actions
	class Behaviour
	{
	public:
		virtual void Enter(Agent* agent) {}
		virtual void Update(Agent* agent, float deltaTime) = 0;
		virtual void Exit(Agent* agent) {}
	};
}
