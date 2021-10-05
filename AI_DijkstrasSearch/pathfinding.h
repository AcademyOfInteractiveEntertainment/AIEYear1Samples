#pragma once
#include "raylib.h"
#include <vector>
#include <algorithm>

namespace pathfinding {
	struct Node;

	struct Edge {
		Edge() { target = nullptr; cost = 0; }
		Edge(Node* _target, float _cost) : target(_target), cost(_cost) {}

		Node* target;
		float cost;
	};

	struct Node {

		Node() {}
		Node(float x, float y) { position.x = x; position.y = y; }

		Vector2 position;

		float gScore;
		Node* previous;

		std::vector<Edge> connections;

		void ConnectTo(Node* other, float cost);
	};

	std::vector<Node*> DijkstrasSearch(Node* startNode, Node* endNode);
	void DrawNode(Node* node, bool selected = false);
	void DrawGraph(Node* node, std::vector<Node*>* drawnList);
}