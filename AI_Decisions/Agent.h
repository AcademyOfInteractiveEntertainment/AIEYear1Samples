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
		Agent(NodeMap* _nodeMap, Behaviour* _behaviour);
		~Agent();

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

		void SetTarget(Agent* _target) { target = _target; }
		Agent* GetTarget() { return target; }
		void SetColor(Color col) { color = col; }

		void Reset() { pathAgent.path.clear(); }

	private:
		PathAgent pathAgent;
		Behaviour* current;
		NodeMap* nodeMap;

		Agent* target;

		Color color;
	};
}