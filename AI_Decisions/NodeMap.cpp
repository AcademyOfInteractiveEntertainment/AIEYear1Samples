#include <iostream>
#include "NodeMap.h"
#include "raylib.h"
#include <raymath.h>

namespace pathfinding
{
    NodeMap::~NodeMap()
    {
        delete[] nodes;
    }

    void NodeMap::Initialise(std::vector<std::string> asciiMap)
    {
        const char emptySquare = '0';

        // assume all strings are the same length, so we'll size the map according to the number of strings and the length of the first one
        height = asciiMap.size();
        width = asciiMap[0].size();

        nodes = new Node * [width * height];

        // loop over the strings, creating Node entries as we go
        for (int y = 0; y < height; y++)
        {
            std::string& line = asciiMap[y];
            // report to the use that you have a mis-matched string length
            if (line.size() != width)
                std::cout << "Mismatched line #" << y << " in ASCII map (" << line.size() << " instead of " << width << ")" << std::endl;

            for (int x = 0; x < width; x++)
            {
                // get the x-th character, or return an empty node if the string isn't long enough 
                char tile = x < line.size() ? line[x] : emptySquare;

                // create a node for anything but a '.' character
                // position it in the middle of the cell, hence the +0.5f's
                nodes[x + width * y] = tile == emptySquare ? nullptr : new Node((x+0.5f) * cellSize, (y+0.5f) * cellSize);
            }
        }

        // now loop over the nodes, creating connections between each node and its neighbour to the West and South on the grid
        // this will link up all nodes 
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                Node* node = GetNode(x, y);
                if (node)
                {
                    // see if there's a node to our west, checking for array overruns first if we're on the west-most edge
                    Node* nodeWest = x == 0 ? nullptr : GetNode(x - 1, y);
                    if (nodeWest)
                    {
                        node->ConnectTo(nodeWest, 1); // TODO weights
                        nodeWest->ConnectTo(node, 1);
                    }

                    // see if there's a node south of us, checking for array index overruns again
                    Node* nodeSouth = y == 0 ? nullptr : GetNode(x, y - 1);
                    if (nodeSouth)
                    {
                        node->ConnectTo(nodeSouth, 1);
                        nodeSouth->ConnectTo(node, 1);
                    }

                    //// diagonals - look to (-1,-1)
                    Node* nodeSouthWest = (x == 0 || y== 0) ? nullptr : GetNode(x - 1, y-1);
                    if (nodeSouthWest)
                    {
                        node->ConnectTo(nodeSouthWest, 1.414f); // TODO weights
                        nodeSouthWest->ConnectTo(node, 1.414f);
                    }

                    // and (+1, -1)
                    Node* nodeSouthEast = (x == width-1 || y == 0) ? nullptr : GetNode(x+1, y - 1);
                    if (nodeSouthEast)
                    {
                        node->ConnectTo(nodeSouthEast, 1.414f);
                        nodeSouthEast->ConnectTo(node, 1.414f);
                    }
                }
            }
        }
    }

    void NodeMap::Draw(bool drawConnections)
    {
        // red blocks
        Color cellColor;
        cellColor.a = 255;
        cellColor.r = 255;
        cellColor.g = 0;
        cellColor.b = 0;

        // grey lines for node edges
        Color lineColor;
        lineColor.a = 255;
        lineColor.r = 128;
        lineColor.g = 128;
        lineColor.b = 128;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                Node* node = GetNode(x, y);
                if (node == nullptr)
                {
                    // draw a solid block in empty squares without a navigation node
                    DrawRectangle(x * cellSize, y * cellSize, cellSize - 1, cellSize - 1, cellColor);
                }
                else
                {
                    // draw the connections between the node and its neighbours
                    for (int i = 0; i < node->connections.size(); i++)
                    {
                        Node* other = node->connections[i].target;
                        DrawLine(node->position.x, node->position.y, other->position.x, other->position.y, lineColor);
                    }
                }
            }
        }
    }

    Node* NodeMap::GetClosestNode(Vector2 worldPos)
    {
        int i = worldPos.x / cellSize;
        if (i < 0 || i >= width) return nullptr;

        int j = worldPos.y / cellSize;
        if (j < 0 || j >= height) return nullptr;

        return GetNode(i, j);
    }

    Node* NodeMap::GetRandomNode()
    {
        Node* node = nullptr;
        while (node == nullptr)
        {
            int x = rand() % width;
            int y = rand() % height;
            node = GetNode(x, y);
        }
        return node;
    }

    bool NodeMap::IsVisibleFrom(Node* start, Node* end)
    {
        // calculate a vector from start to end that is one cellsize in length
        Vector2 delta = Vector2Subtract(end->position, start->position);
        float distance =Vector2Distance(end->position, start->position);
        delta = Vector2Scale(delta, cellSize/distance);

        // step forward in that direction one cell at a time from start towards end
        for (float cells = 1.0f; cells < distance/cellSize; cells += 1.0f)
        {
            Vector2 testPosition = Vector2Add(start->position, Vector2Scale(delta, cells));
            // if the square below in unpassable, then we don;t have line of sight from start to end
            if (GetClosestNode(testPosition) == nullptr)
                return false;
        }

        // we've travelled the whole path without hitting an obstacle!
        return true;
    }

    std::vector<Node*> NodeMap::SmoothPath(std::vector<Node*> path)
    {
        if (path.size() == 0)
            return path;

        std::vector<Node*> smoothed;
        Node* start = path[0];
        smoothed.push_back(start);
        for (int i = 0; i < path.size(); i++)
        {
            // keep stepping over the nodes we can see from start
            while (i< path.size() -1 && IsVisibleFrom(start, path[i + 1]))
                i++;

            start = path[i];

            // add the last node we can see to our path, and set it as the new start
            smoothed.push_back(start);
        }

        return smoothed;
    }
}



