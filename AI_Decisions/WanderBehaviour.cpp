#include "WanderBehaviour.h"
#include "Agent.h"
#include "NodeMap.h"

namespace pathfinding
{
	void WanderBehaviour::Update(Agent* agent, float deltaTime)
	{
		if (agent->PathComplete())
		{
			Node* node = agent->GetNodeMap()->GetRandomNode();
			agent->GoTo(node);
		}
	}
}