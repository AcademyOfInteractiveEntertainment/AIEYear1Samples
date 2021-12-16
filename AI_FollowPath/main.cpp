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

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "PathFollower.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Path Follower");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    PathFollower follower;

    // create a circular path for the follower, centred to fit on the screen
    float radius = 160;
    for (int i = 0; i < 24; i++)
    {
        float angle = (i * 6.283f) / 24;
        // uncomment the rest of the line to get a bendy track
        float bend = 1.0f; // +0.3f * sinf(angle * 3.7f);
        follower.AddPoint({ (1.5f + cosf(angle) * bend) * radius , (1.5f + sinf(angle) * bend) * radius });
    }

    // position the agent
    follower.SetPosition(radius / 2, radius/2);

    float time = (float)GetTime();
    float deltaTime;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float fTime = (float)GetTime();
        deltaTime = fTime - time;
        time = fTime;

        // cap the elapsed time for when we stop and debug
        if (deltaTime > 0.1f)
            deltaTime = 0.1f;

        // Update
        follower.Update(deltaTime);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        follower.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}