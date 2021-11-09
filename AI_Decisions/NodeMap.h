#pragma once
#include <string>
#include "pathfinding.h"

namespace pathfinding
{
	// class that represents the nodes on a map, shared between all Pathfind objects
	// this data is initialised and startup and doesn't change at runtime
	class NodeMap
	{
	public:
		int width, height;
		float cellSize;

		Node** nodes;

		void Initialise(std::vector<std::string> asciiMap);
		void Draw(bool drawConnections);

		// utility functions 
		Node* GetNode(int x, int y) { return nodes[x + width * y]; }
		Node* GetClosestNode(Vector2 worldPos);

		Node* GetRandomNode();
	};
}

