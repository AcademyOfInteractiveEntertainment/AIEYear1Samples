#include "Graph.h"
#include "raylib.h"
#include "raymath.h"

Graph::Graph()
{
	m_texture = LoadTexture("nodeTexture.png");
}


Graph::~Graph()
{
	for (std::list<Node*>::iterator nit = m_nodeList.begin(); nit != m_nodeList.end(); nit++)
	{
		for (std::list<Edge*>::iterator eit = (*nit)->m_edgeList.begin(); eit != (*nit)->m_edgeList.end(); eit++)
		{
			Edge* edge = *eit;
			if (*nit != nullptr && edge->m_nodeA != *nit)
				edge->m_nodeA->m_edgeList.remove(edge);

			if (*nit != nullptr && edge->m_nodeB != *nit)
				edge->m_nodeB->m_edgeList.remove(edge);

			delete edge;
			*eit = nullptr;
		}
		delete* nit;
		*nit = nullptr;
	}

	UnloadTexture(m_texture);
}

Graph::Node* Graph::AddNode(Vector2 position)
{
	Node* node = new Node();
	node->m_position = position;
	m_nodeList.push_back(node);
	return node;
}

// find node with value
Graph::Node* Graph::FindNode(Vector2 position)
{
	for (std::list<Node*>::iterator it = m_nodeList.begin(); it != m_nodeList.end(); it++)
	{
		if ((*it)->m_position.x == position.x && (*it)->m_position.y == position.y)
			return *it;
	}
	return nullptr;
}

void Graph::FindNodes(std::list<Node*>& list, Vector2 position, float distance)
{
	for (std::list<Node*>::iterator it = m_nodeList.begin(); it != m_nodeList.end(); it++)
	{
		Node* node = *it;
		float mag = Vector2Length(Vector2Subtract(node->m_position, position));
		
		if (mag < distance)
			list.push_back(node);
	}
}

// remove the given node
void Graph::RemoveNode(Node* pNode)
{
	for (std::list<Edge*>::iterator it = pNode->m_edgeList.begin(); it != pNode->m_edgeList.end(); it++)
	{
		Edge* edge = *it;
		if (edge->m_nodeA != pNode)
			edge->m_nodeA->m_edgeList.remove(edge);

		if (edge->m_nodeB != pNode)
			edge->m_nodeB->m_edgeList.remove(edge);

		delete edge;
	}
	m_nodeList.remove(pNode);
}

void Graph::ConnectNodes(Node* nodeA, Node* nodeB, int cost)
{
	Edge* edge = new Edge();
	edge->m_iCost = cost;
	edge->m_nodeA = nodeA;
	edge->m_nodeB = nodeB;

	nodeA->m_edgeList.push_back(edge);
	nodeB->m_edgeList.push_back(edge);
}

void Graph::Draw()
{
	// draw all lines
	for (std::list<Node*>::iterator nit = m_nodeList.begin(); nit != m_nodeList.end(); nit++)
	{
		Node* node = *nit;
		for (std::list<Edge*>::iterator eit = node->m_edgeList.begin(); eit != node->m_edgeList.end(); eit++)
		{
			Edge* edge = *eit;
			DrawLine(edge->m_nodeA->m_position.x, edge->m_nodeA->m_position.y, edge->m_nodeB->m_position.x, edge->m_nodeB->m_position.y, WHITE);
		}
	}
	// draw nodes on top of lines
	for (std::list<Node*>::iterator nit = m_nodeList.begin(); nit != m_nodeList.end(); nit++)
	{
		Node* node = *nit;
		DrawTexture(m_texture, node->m_position.x - (m_texture.width >> 1), node->m_position.y - (m_texture.height >> 1), WHITE);
	}
}