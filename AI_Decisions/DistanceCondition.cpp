#include "Condition.h"
#include "DistanceCondition.h"
#include "Agent.h"
#include "raymath.h"

namespace AIForGames
{
	bool DistanceCondition::IsTrue(Agent* agent)
	{
		return (Vector2Distance(agent->GetPosition(), agent->GetTarget()->GetPosition()) < m_distance) == m_lessThan;
	}
}