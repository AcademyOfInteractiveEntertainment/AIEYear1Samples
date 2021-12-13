#pragma once
#include <string>
#include <vector>
#include "pathfinding.h"

namespace AIForGames
{
	// class that represents the nodes on a map, shared between all Pathfind objects
	// this data is initialised and startup and doesn't change at runtime
	class NodeMap
	{
	public:
		~NodeMap();

		int m_width, m_height;
		float m_cellSize;

		Node** m_nodes;

		void Initialise(std::vector<std::string> asciiMap);
		void Draw(bool drawConnections);

		// utility functions 
		Node* GetNode(int x, int y) { return m_nodes[x + m_width * y]; }
		Node* GetClosestNode(Vector2 worldPos);

		Node* GetRandomNode();

		bool IsVisibleFrom(Node* start, Node* end);
		std::vector<Node*> SmoothPath(std::vector<Node*> path);
	};

}

