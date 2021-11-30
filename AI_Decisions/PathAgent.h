#pragma once
#include "raylib.h"
#include "pathfinding.h"
#include <vector>

namespace pathfinding
{
	class NodeMap;

	class PathAgent
	{
	public:
		PathAgent() : currentIndex(-1), currentNode(nullptr), speed(100.0f), acceleration(500.0f) { velocity.x = 0; velocity.y = 0; }
		Vector2 position;
		Vector2 velocity;

		float acceleration;

		std::vector<Node*> path;
		int currentIndex;
		Node* currentNode;

		float speed;
		NodeMap* nodeMap;

		void SetNode(Node* node);
		void Update(float deltaTime);

		void UpdateLinear(float deltaTime);
		void UpdatePhysics(float deltaTime);

		void GoToNode(Node* node);
	};
}
