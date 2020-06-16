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
#include "MyStack.h"

struct Pancake {
    Texture2D texture;
    int y;
};

// callback function to draw the pancake in the stack
void drawPancake(const Pancake* pPancake) {
    DrawTexture(pPancake->texture, 300, pPancake->y, WHITE);
}

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    MyStack<Pancake> pancakeStack(5);
    int waitTimer = 0;

    // Now load some sprites
    for (int i = 0; i < 6; i++) {
        Pancake p;
        p.texture = LoadTexture("pancake.png");
        p.y = 300 - (i * 50);
        pancakeStack.push(p);
    }

    //--------------------------------------------------------------------------------------

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

        ClearBackground(RAYWHITE);

        // eat the pancake - get the item on the top of the stack, destroy the item, then pop the stack
        if (IsKeyPressed(KEY_DOWN) && pancakeStack.isEmpty() == false) {
            const Pancake* p = pancakeStack.top();
            UnloadTexture(p->texture);
            pancakeStack.pop();
        }
        // mum made a new pancake, add it to the top of the stack
        if (IsKeyPressed(KEY_UP)) {
            Pancake p;
            p.texture = LoadTexture("pancake.png");
            p.y = 300 - (pancakeStack.getSize() * 50);
            pancakeStack.push(p);
        }

        if (pancakeStack.isEmpty() == false) {
            pancakeStack.draw(drawPancake);
        }


        DrawText("Press UP or DOWN to add or remove pancakes", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   

    while (pancakeStack.isEmpty() == false) {
        const Pancake* p = pancakeStack.top();
        UnloadTexture(p->texture);
        pancakeStack.pop();
    }

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}