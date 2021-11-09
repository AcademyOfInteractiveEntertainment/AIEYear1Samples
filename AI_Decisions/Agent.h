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
		void GoTo(Node* node);

		std::vector<Node*>& GetPath() { return pathAgent.path; }

		void SetNode(Node* node);

		bool PathComplete();

		NodeMap* GetNodeMap() { return nodeMap; }
		Vector2 GetPosition() { return pathAgent.position; }

		void SetSpeed(float speed) { pathAgent.speed = speed; }

	private:
		PathAgent pathAgent;
		Behaviour* current;
		NodeMap* nodeMap;
	};
}