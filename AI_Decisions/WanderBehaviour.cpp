#include "WanderBehaviour.h"
#include "Agent.h"
#include "NodeMap.h"

namespace pathfinding
{
	void WanderBehaviour::Enter(Agent* agent)
	{
		// cyan when wandering
		agent->SetColor({ 0,255,255,255 });

		agent->Reset();
	}

	void WanderBehaviour::Update(Agent* agent, float deltaTime)
	{
		if (agent->PathComplete())
		{
			Node* node = agent->GetNodeMap()->GetRandomNode();
			agent->GoTo(node);
		}
	}
}