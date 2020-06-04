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

#include "BinaryTree.h"
#include "TreeNode.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------


    BinaryTree m_binaryTree;
    TreeNode* m_selectedNode = nullptr;


    int valueBoxValue = 0;
    bool valueBoxEditMode = false;

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

        GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);
        
        if(GuiValueBox(Rectangle{ 25, 25, 125, 30 }, NULL, &valueBoxValue, 0, 100, valueBoxEditMode)) valueBoxEditMode = !valueBoxEditMode;

        if (GuiButton(Rectangle { 160, 25, 125, 30 }, GuiIconText(RICON_OK_TICK, "Insert")))
        {
            // Implement the code to insert valueBoxValue into your binary tree here! 
            //m_binaryTree.Insert(valueBoxValue);
            //m_selectedNode = m_binaryTree.Find(valueBoxValue);
        }

        if (GuiButton(Rectangle{ 160, 60, 125, 30 }, GuiIconText(RICON_CROSS, "Remove")))
        {
            // Implement the code to remove the node with value = valueBoxValue from your binary tree here! 
            //m_binaryTree.Remove(valueBoxValue);
        }

        // draw the binary tree
        m_binaryTree.Draw(m_selectedNode);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}