#pragma once
#include <list>
#include "raylib.h"

class Graph
{
public:
	class Edge;

	class Node
	{
	public:
		Vector2 m_position;
		std::list<Edge*> m_edgeList;
	};

	class Edge
	{
	public:
		Node* m_nodeA;
		Node* m_nodeB;
		int m_iCost;
	};

public:

	Graph();
	virtual ~Graph();

	Node* AddNode(Vector2 position);
	Node* FindNode(Vector2 position);			// find node with value
	void FindNodes(std::list<Node*>& list, Vector2 position, float distance);

	void RemoveNode(Node* pNode);			// remove the given node

	void ConnectNodes(Node* nodeA, Node* nodeB, int cost = 1);

	void Draw();

protected:
	// List of Nodes
	std::list<Node*> m_nodeList;

	Texture2D m_texture;
};

