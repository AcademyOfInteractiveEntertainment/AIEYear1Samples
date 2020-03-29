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
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Agent.h"
#include "KeyboardBehaviour.h"
#include "FleeBehaviour.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    Agent* player = new Agent();
    KeyboardBehaviour* keyboardBehaviour = new KeyboardBehaviour();
    player->AddBehaviour(keyboardBehaviour);

    Agent* fleeAgent = new Agent();
    fleeAgent->SetPosition({ (float)(screenWidth >> 1), (float)(screenHeight >> 1) });
    FleeBehaviour* fleeBehaviour = new FleeBehaviour();
    fleeBehaviour->SetTarget(player);    
    fleeAgent->AddBehaviour(fleeBehaviour);

        
    float deltaTime = 0;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        deltaTime = GetFrameTime();

        player->Update(deltaTime);
        fleeAgent->Update(deltaTime);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        player->Draw();
        fleeAgent->Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    delete keyboardBehaviour;
    delete fleeBehaviour;
    delete player;
    delete fleeAgent;


    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}