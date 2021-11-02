#include "Agent.h"
#include "NodeMap.h"

namespace pathfinding
{
	void Agent::Update(float deltaTime)
	{
		if (current)
			current->Do(this);
		pathAgent.Update(deltaTime);
	}

	void Agent::Draw()
	{
		DrawCircle(pathAgent.position.x, pathAgent.position.y, 8, { 255,255,0,255 });
	}

	void Agent::GoTo(Vector2 point)
	{
		Node* end = nodeMap->GetClosestNode(point);
		pathAgent.GoToNode(end);
	}

	void Agent::SetNode(Node* node)
	{
		pathAgent.SetNode(node);
	}
}