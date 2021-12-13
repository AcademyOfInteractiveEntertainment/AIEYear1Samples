#pragma once
#include "raylib.h"
#include "pathfinding.h"
#include <vector>

namespace AIForGames
{
	class NodeMap;

	class PathAgent
	{
	public:
		PathAgent() : m_currentIndex(-1), m_currentNode(nullptr), m_speed(100.0f), m_acceleration(500.0f) { m_velocity.x = 0; m_velocity.y = 0; }

		Vector2 m_position;
		Vector2 m_velocity;

		float m_acceleration;

		std::vector<Node*> m_path;
		int m_currentIndex;
		Node* m_currentNode;

		float m_speed;
		NodeMap* m_nodeMap;

		void SetNode(Node* node);
		void Update(float deltaTime);

		void UpdateLinear(float deltaTime);
		void UpdatePhysics(float deltaTime);

		void GoToNode(Node* node);
	};
}
