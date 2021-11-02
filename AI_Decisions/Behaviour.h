#pragma once
namespace pathfinding
{
	class Agent;

	// abstract base class for all actions
	class Behaviour
	{
	public:
		virtual void Do(Agent* agent) = 0;
	};
}
