#pragma once
#include "PathAgent.h"
#include "Behaviour.h"

namespace AIForGames
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

		std::vector<Node*>& GetPath() { return m_pathAgent.GetPath(); }

		void SetNode(Node* node);

		bool PathComplete();

		NodeMap* GetNodeMap() { return m_nodeMap; }
		Vector2 GetPosition() { return m_pathAgent.GetPosition(); }

		void SetSpeed(float speed) { m_pathAgent.SetSpeed(speed); }

		void SetTarget(Agent* target) { m_target = target; }
		Agent* GetTarget() { return m_target; }
		void SetColor(Color col) { m_color = col; }

		void Reset() { m_pathAgent.GetPath().clear(); }

	private:
		PathAgent m_pathAgent;
		Behaviour* m_current;
		NodeMap* m_nodeMap;

		Agent* m_target;

		Color m_color;
	};
}