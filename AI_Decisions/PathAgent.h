#pragma once
#include "raylib.h"
#include "pathfinding.h"
#include <vector>

namespace pathfinding
{
	class PathAgent
	{
	public:
		PathAgent() : currentIndex(-1), currentNode(nullptr), speed(100.0f) {}
		Vector2 position;

		std::vector<Node*> path;
		int currentIndex;
		Node* currentNode;

		float speed;

		void SetNode(Node* node);
		void Update(float deltaTime);
		void GoToNode(Node* node);
	};
}
