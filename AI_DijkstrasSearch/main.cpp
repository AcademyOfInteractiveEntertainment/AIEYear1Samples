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

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        //Draw the graph
        std::vector<Node*>* drawnList = new std::vector<Node*>();
        DrawGraph(a, drawnList);
        delete drawnList;

        //Draw the shortest path
        for (Node* node : shortestPath) {
            DrawNode(node, true);
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}