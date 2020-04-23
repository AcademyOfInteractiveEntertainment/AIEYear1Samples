#pragma once
#include "raylib.h"
#include <vector>
#include <algorithm>

namespace pathfinding {
	struct Node;

	struct Edge {
		Node* target;
		float cost;
	};

	struct Node {
		Vector2 position;

		float gScore;
		Node* previous;

		std::vector<Edge> connections;
	};

	std::vector<Node*> DijkstrasSearch(Node* startNode, Node* endNode);
	void DrawNode(Node* node, bool selected = false);
	void DrawGraph(Node* node, std::vector<Node*>* drawnList);
}