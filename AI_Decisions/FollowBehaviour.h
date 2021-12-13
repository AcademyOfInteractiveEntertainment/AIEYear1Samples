#pragma once
#include "pathfinding.h"
#include "Behaviour.h"

namespace AIForGames
{
    class FollowBehaviour : public Behaviour
    {
	private:
		Vector2 m_lastTargetPosition;

	public:
		FollowBehaviour() { m_lastTargetPosition.x = 0; m_lastTargetPosition.y = 0; }

		virtual void Enter(Agent* agent);
		virtual void Update(Agent* agent, float deltaTime);

		virtual float Evaluate(Agent* agent);
    };
}

