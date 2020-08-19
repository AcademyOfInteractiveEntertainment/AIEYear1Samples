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
#include "WanderBehaviour.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    Agent* wanderer = new Agent();
    wanderer->SetPosition({ (float)(screenWidth >> 1), (float)(screenHeight >> 1) });
    wanderer->SetMaxSpeed(50);
    WanderBehaviour* wanderBehaviour = new WanderBehaviour();
    wanderer->AddBehaviour(wanderBehaviour);

        
    float deltaTime = 0;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        deltaTime = GetFrameTime();
        wanderer->Update(deltaTime);

        Vector2 pos = wanderer->GetPosition();
        if (pos.y < 0)
            pos.y = screenHeight;
        if (pos.y > screenHeight)
            pos.y = 0;
        if (pos.x < 0)
            pos.x = screenWidth;
        if (pos.x > screenWidth)
            pos.x = 0;
        wanderer->SetPosition(pos);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        wanderBehaviour->Draw(wanderer);    // debug only
        wanderer->Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    delete wanderBehaviour;
    delete wanderer;


    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}