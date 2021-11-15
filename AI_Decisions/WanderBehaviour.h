#pragma once
#include "pathfinding.h"
#include "Behaviour.h"

namespace pathfinding
{
	class WanderBehaviour : public Behaviour
	{
	public:

		virtual void Enter(Agent* agent);
		virtual void Update(Agent* agent, float deltaTime);
	};
}
