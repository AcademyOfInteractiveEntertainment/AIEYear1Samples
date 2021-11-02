#pragma once
#include "PathAgent.h"
#include "Behaviour.h"

namespace pathfinding
{
	class NodeMap;

	class Agent
	{
	public:
		Agent();
		Agent(NodeMap* _nodeMap, Behaviour* _behaviour) : current(_behaviour), nodeMap(_nodeMap) {}

		void Update(float deltaTime);
		void Draw();

		void GoTo(Vector2 point);

		std::vector<Node*>& GetPath() { return pathAgent.path; }

		void SetNode(Node* node);

	private:
		PathAgent pathAgent;
		Behaviour* current;
		NodeMap* nodeMap;
	};
}