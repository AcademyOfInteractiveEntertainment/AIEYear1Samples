#pragma once
#include "pathfinding.h"
#include "Behaviour.h"

namespace pathfinding
{
    class FollowBehaviour : public Behaviour
    {
	private:
		Agent* target;
		Vector2 lastTargetPosition;

	public:
		FollowBehaviour(Agent* _target) : target(_target) { lastTargetPosition.x = 0; lastTargetPosition.y = 0; }
		virtual void Update(Agent* agent, float deltaTime);
    };
}

