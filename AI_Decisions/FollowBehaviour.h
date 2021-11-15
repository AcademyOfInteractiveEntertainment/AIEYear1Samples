#pragma once
#include "pathfinding.h"
#include "Behaviour.h"

namespace pathfinding
{
    class FollowBehaviour : public Behaviour
    {
	private:
		Vector2 lastTargetPosition;

	public:
		FollowBehaviour() { lastTargetPosition.x = 0; lastTargetPosition.y = 0; }

		virtual void Enter(Agent* agent);
		virtual void Update(Agent* agent, float deltaTime);
    };
}

