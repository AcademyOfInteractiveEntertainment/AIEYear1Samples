#pragma once
#include <string>
#include "Node.h"

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
};

