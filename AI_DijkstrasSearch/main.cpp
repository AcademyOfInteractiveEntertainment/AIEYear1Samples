/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>
#include "pathfinding.h"
#include "NodeMap.h"
#include "PathAgent.h"

using namespace pathfinding;

int main(int argc, char* argv[])
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	//Nodes
	Node* a = new Node();
	a->position = Vector2{ 125.0f, 75.0f };
	Node* b = new Node();
	b->position = Vector2{ 250.0f, 75.0f };
	Node* c = new Node();
	c->position = Vector2{ 250.0f, 150.0f };
	Node* d = new Node();
	d->position = Vector2{ 250.0f, 225.0f };
	Node* e = new Node();
	e->position = Vector2{ 187.0f, 300.0f };
	Node* f = new Node();
	f->position = Vector2{ 125.0f, 225.0f };
	//Edges
	a->connections.push_back(Edge{ b, 2 });
	a->connections.push_back(Edge{ f, 5 });
	b->connections.push_back(Edge{ c, 3 });
	c->connections.push_back(Edge{ a, 3 });
	c->connections.push_back(Edge{ d, 1 });
	d->connections.push_back(Edge{ e, 4 });
	d->connections.push_back(Edge{ f, 4 });
	f->connections.push_back(Edge{ e, 6 });

	std::vector<Node*> shortestPath = DijkstrasSearch(a, e);

	for (Node* node : shortestPath) {
		std::cout << node->gScore << std::endl;
	}

	// create a map of nodes from some grid-based ASCII art
	NodeMap nodeMap;
	nodeMap.cellSize = 32;
	std::vector<std::string> asciiMap;
	asciiMap.push_back("000000000000");
	asciiMap.push_back("010111011100");
	asciiMap.push_back("010101110110");
	asciiMap.push_back("011100000010");
	asciiMap.push_back("010111111110");
	asciiMap.push_back("010000001000");
	asciiMap.push_back("011111111110");
	asciiMap.push_back("000000000000");
	nodeMap.Initialise(asciiMap);

	Node* start = nodeMap.GetNode(1, 1);
	Node* end = nodeMap.GetNode(10, 2);
	std::vector<Node*> nodeMapPath = DijkstrasSearch(start, end);
	Color lineColor = { 255, 255, 255, 255 };

	PathAgent agent;
	agent.SetNode(start);
	agent.speed = 64;

    float time = (float)GetTime();
    float deltaTime;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float fTime = (float)GetTime();
        deltaTime = fTime - time;
        time = fTime;
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        bool drawNodeMap = true;

        nodeMap.Draw(true);
        DrawPath(agent.path, lineColor);

        // read mouseclicks, left for start node, end for right node
        if (IsMouseButtonPressed(0))
        {
            Vector2 mousePos = GetMousePosition();
            Node* end = nodeMap.GetClosestNode(mousePos);
            agent.GoToNode(end);
        }

        //if (IsMouseButtonPressed(1))
        //{
        //	Vector2 mousePos = GetMousePosition();
        //	end = nodeMap.GetClosestNode(mousePos);
        //	nodeMapPath = DijkstrasSearch(start, end);
        //}
        agent.Update(deltaTime);
        agent.Draw();

        EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}