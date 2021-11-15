#include "Condition.h"
#include "DistanceCondition.h"
#include "Agent.h"
#include "raymath.h"

namespace pathfinding
{
	bool DistanceCondition::IsTrue(Agent* agent)
	{
		return (Vector2Distance(agent->GetPosition(), agent->GetTarget()->GetPosition()) < distance) == lessThan;
	}
}