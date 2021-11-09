#pragma once
#include "pathfinding.h"
#include "Behaviour.h"

namespace pathfinding
{
	class WanderBehaviour : public Behaviour
	{
	private:
		Node* target;

	public:
		WanderBehaviour() : target(nullptr) {}
		virtual void Update(Agent* agent, float deltaTime);
	};
}
