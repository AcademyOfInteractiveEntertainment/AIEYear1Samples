#include "pathfinding.h"
#include <algorithm>
#include <vector> 

namespace pathfinding
{
	//Use this function to sort nodes using their gScore value
	bool NodeSort(Node* i, Node* j) 
	{ 
		return (i->gScore < j->gScore); 
	}

	void Node::ConnectTo(Node* other, float cost)
	{
		connections.push_back(Edge(other, cost));
	}

	std::vector<Node*> DijkstrasSearch(Node* startNode, Node* endNode)
	{
		//Validate the input
		if (startNode == nullptr || endNode == nullptr)
		{
			return std::vector<Node*>();
		}

		if (startNode == endNode)
		{
			std::vector<Node*> singleNodePath;
			singleNodePath.push_back(startNode);
			return singleNodePath;
		}

		//Initialize the starting node
		startNode->gScore = 0;
		startNode->previous = nullptr;

		//Create our temporary lists for storing nodes
		std::vector<Node*> openList;
		std::vector<Node*> closedList;

		//Add the starting node to openList
		openList.push_back(startNode);


		while (!openList.empty())
		{
			//Sort openList based on gScore using the function created above
			std::sort(openList.begin(), openList.end(), NodeSort);

			//Set the current node to the first node in the openList
			Node* currentNode = openList.front();
			//Remove currentNode from openList
			openList.erase(openList.begin());
			//Add currentNode to closedList
			closedList.push_back(currentNode);

			//If the destination node was added to the closed list,
			//the shortest path has been found
			if (currentNode == endNode)
			{
				break;
			}

			//For each Edge e in currentNode's connections
			for (Edge e : currentNode->connections)
			{
				//If the target node is in the closedList, ignore it
				if (std::find(closedList.begin(), closedList.end(), e.target) != closedList.end()) {
					continue;
				}
				//If the target node is not in the openList, update it
				if (std::find(openList.begin(), openList.end(), e.target) == openList.end()) {
					//Calculate the target node's G Score
					e.target->gScore = currentNode->gScore + e.cost;
					//Set the target node's previous to currentNode
					e.target->previous = currentNode;
					//Find the earliest point we should insert the node
					//to the list to keep it sorted
					auto insertionPos = openList.end();
					for (auto i = openList.begin(); i != openList.end(); i++) {
						if (e.target->gScore < (*i)->gScore) {
							insertionPos = i;
							break;
						}
					}
					//Insert the node at the appropriate position
					openList.insert(insertionPos, e.target);
				}
				//Otherwise the target node IS in the open list
				else {
					//Compare the new G Score to the old one before updating
					if (currentNode->gScore + e.cost < e.target->gScore) {
						//Calculate the target node's G Score
						e.target->gScore = currentNode->gScore + e.cost;
						//Set the target node's previous to currentNode
						e.target->previous = currentNode;
					}
				}
			}
		}

		//Create path in reverse from endNode to startNode
		std::vector<Node*> path;
		Node* currentNode = endNode;

		while (currentNode != nullptr)
		{
			//Add the current node to the beginning of the path
			path.insert(path.begin(), currentNode);
			//Go to the previous node
			currentNode = currentNode->previous;
		}

		return path;
	}

	void DrawPath(std::vector<Node*>& path, Color lineColor)
	{
		for (int i = 1; i < path.size(); i++)
			DrawLine(path[i - 1]->position.x, path[i - 1]->position.y, path[i]->position.x, path[i]->position.y, lineColor);
	}

	void DrawNode(Node* node, bool selected)
	{
		static char buffer[10];
		sprintf_s(buffer, "%.0f", node->gScore);

		//Draw the circle for the outline
		DrawCircle(node->position.x, node->position.y, 25, YELLOW);
		//Draw the inner circle
		if (selected)
		{
			DrawCircle(node->position.x, node->position.y, 22, BROWN);
		}
		else
		{
			DrawCircle(node->position.x, node->position.y, 22, BLACK);
		}
		//Draw the text
		DrawText(buffer, node->position.x - 10, node->position.y - 10, 15, WHITE);
	}

	void DrawGraph(Node* node, std::vector<Node*>* drawnList)
	{
		DrawNode(node);
		drawnList->push_back(node);

		//For each Edge in this node's connections
		for (Edge e : node->connections)
		{
			//Draw the Edge
			DrawLine(node->position.x, node->position.y, e.target->position.x, e.target->position.y, WHITE);
			//Draw the cost
			Vector2 costPos = { (node->position.x + e.target->position.x) / 2, (node->position.y + e.target->position.y) / 2 };
			static char buffer[10];
			sprintf_s(buffer, "%.0f", e.cost);
			DrawText(buffer, costPos.x, costPos.y, 15, WHITE);
			//Draw the target node
			if (std::find(drawnList->begin(), drawnList->end(), e.target) == drawnList->end())
			{
				DrawGraph(e.target, drawnList);
			}
		}
	}
}