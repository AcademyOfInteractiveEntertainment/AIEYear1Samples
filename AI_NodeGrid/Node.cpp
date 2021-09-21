#include "Node.h"

void Node::ConnectTo(Node* other, float cost)
{
	connections.push_back(Connection(other, cost));
}
