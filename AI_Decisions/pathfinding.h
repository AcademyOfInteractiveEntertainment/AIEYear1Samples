#pragma once
#include "raylib.h"
#include <vector>
#include <algorithm>

namespace AIForGames {
	struct Node;

	struct Edge {
		Edge() { target = nullptr; cost = 0; }
		Edge(Node* _target, float _cost) : target(_target), cost(_cost) {}

		Node* target;
		float cost;
	};

	struct Node {

		Node() { position.x = 0; position.y = 0; gScore = 0; previous = nullptr; }
		Node(float x, float y) { position.x = x; position.y = y; gScore = 0; previous = nullptr; }

		Vector2 position;

		float gScore;
		Node* previous;

		std::vector<Edge> connections;

		void ConnectTo(Node* other, float cost);
	};

	std::vector<Node*> DijkstrasSearch(Node* startNode, Node* endNode);
	void DrawPath(std::vector<Node*>& path, Color lineColor);
}