#pragma once
#include <vector>
class Node
{
public:
	Node(float _x, float _y) : x(_x), y(_y) {}

	void ConnectTo(Node* other, float cost);

	float x, y;

	struct Connection
	{
		Connection() { node = nullptr; cost = 0; }
		Connection(Node* _node, float _cost) : node(_node), cost(_cost) {}

		Node* node;
		float cost;
	};

	std::vector<Connection> connections;
};

