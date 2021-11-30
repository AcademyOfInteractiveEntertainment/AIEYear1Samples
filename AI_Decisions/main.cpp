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
#include "Agent.h"
#include "GotoPointBehaviour.h"
#include "WanderBehaviour.h"
#include "FollowBehaviour.h"
#include "SelectorBehaviour.h"
#include "DistanceCondition.h"
#include "State.h"
#include "FiniteStateMachine.h"
#include "UtilityAI.h"
#include "Utilities.h"

using namespace pathfinding;

int main(int argc, char* argv[])
{
    //float weights[] = { 5,1,4 };
    //int hits[3] = { 0,0,0 };
    //for (int i = 0; i < 10000; i++)
    //{
    //    hits[Utilities::GetRouletteIndex(weights, 3)]++;
    //}

    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // create a map of nodes from some grid-based ASCII art
    NodeMap nodeMap;
    nodeMap.cellSize = 32;
    std::vector<std::string> asciiMap;
    //asciiMap.push_back("000000000000");
    //asciiMap.push_back("010111011100");
    //asciiMap.push_back("010101110110");
    //asciiMap.push_back("011100000010");
    //asciiMap.push_back("010111111110");
    //asciiMap.push_back("010000001000");
    //asciiMap.push_back("011111111110");
    //asciiMap.push_back("000000000000");

    asciiMap.push_back("000000000000000000000000");
    asciiMap.push_back("011101111111111111111110");
    asciiMap.push_back("011101111111111111111110");
    asciiMap.push_back("011101100000000000000110");
    asciiMap.push_back("011101111111110111111110");
    asciiMap.push_back("011101111111110111000000");
    asciiMap.push_back("011101111101110111111110");
    asciiMap.push_back("011101111101110000011110");
    asciiMap.push_back("011101111101111111111110");
    asciiMap.push_back("011111111100000000001110");
    asciiMap.push_back("011110111101111111111110");
    asciiMap.push_back("011110111101111111111110");
    asciiMap.push_back("011110111101111111111110");
    asciiMap.push_back("011110111111111111111110");
    asciiMap.push_back("000000000000000000000000");

    nodeMap.Initialise(asciiMap);

    Node* start = nodeMap.GetNode(1, 1);
    Node* end = nodeMap.GetNode(10, 2);
    std::vector<Node*> nodeMapPath = DijkstrasSearch(start, end);
    Color lineColor = { 255, 255, 255, 255 };

    Agent agent(&nodeMap, new GotoPointBehaviour());
    agent.SetNode(start);

    Agent agent2(&nodeMap, new WanderBehaviour());
    agent2.SetNode(nodeMap.GetRandomNode());

    // set up a FSM, we're going to have two states with their own conditions
    DistanceCondition* closerThan5 = new DistanceCondition(5.0f * nodeMap.cellSize, true);
    DistanceCondition* furtherThan7 = new DistanceCondition(7.0f * nodeMap.cellSize, false);

    // register these states with the FSM, so its responsible for deleting them now
    State* wanderState = new State(new WanderBehaviour());
    State* followState = new State(new FollowBehaviour());
    wanderState->AddTransition(closerThan5, followState);
    followState->AddTransition(furtherThan7, wanderState);

    // make a finite state machine that starts off wandering
    FiniteStateMachine* fsm = new FiniteStateMachine(wanderState);
    fsm->AddState(wanderState);
    fsm->AddState(followState);

    UtilityAI* utilityAI = new UtilityAI();
    utilityAI->AddBehaviour(new WanderBehaviour());
    utilityAI->AddBehaviour(new FollowBehaviour());

    Agent agent3(&nodeMap, utilityAI);
    agent3.SetNode(nodeMap.GetRandomNode());
    agent3.SetTarget(&agent);
    agent3.SetSpeed(32);

    float time = (float)GetTime();
    float deltaTime;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float fTime = (float)GetTime();
        deltaTime = fTime - time;
        time = fTime;
        
        // cap the elapsed time for when we debug
        if (deltaTime > 0.1f)
            deltaTime = 0.1f;

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
        DrawPath(agent.GetPath(), lineColor);

        agent.Update(deltaTime);
        agent.Draw();

        //agent2.Update(deltaTime);
        //agent2.Draw();

        //agent3.Update(deltaTime);
        //agent3.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}