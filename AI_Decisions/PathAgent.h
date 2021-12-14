#pragma once
#include "raylib.h"
#include "pathfinding.h"
#include <vector>

namespace AIForGames
{
	class NodeMap;

	class PathAgent
	{
	private:
		Vector2 m_position;
		Vector2 m_velocity;

		float m_acceleration;

		std::vector<Node*> m_path;
		int m_currentIndex;
		Node* m_currentNode;

		float m_speed;
		NodeMap* m_nodeMap;

	public:
		PathAgent() : m_currentIndex(-1), m_currentNode(nullptr), m_speed(100.0f), m_acceleration(500.0f), m_nodeMap(nullptr) { m_position.x = 0; m_position.y = 0; m_velocity.x = 0; m_velocity.y = 0; }

		void SetNode(Node* node);
		void Update(float deltaTime);

		void UpdateLinear(float deltaTime);
		void UpdatePhysics(float deltaTime);

		void GoToNode(Node* node);

		std::vector<Node*>& GetPath() { return m_path; }

		Vector2 GetPosition() { return m_position; }
		void SetPosition(Vector2 position) { m_position = position; }
		float GetSpeed() { return m_speed; }
		void SetSpeed(float speed) { m_speed = speed; }
		NodeMap* GetNodeMap() { return m_nodeMap; }
		void SetNodeMap(NodeMap* nodeMap) { m_nodeMap = nodeMap; }
	};
}
