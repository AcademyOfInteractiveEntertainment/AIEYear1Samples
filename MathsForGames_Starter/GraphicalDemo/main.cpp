/*******************************************************************************************
*
*   aie reference - Graphical Demo Starter
*
********************************************************************************************/

#include "raylib-cpp.hpp"

#include "SpriteObject.h"
#include "TankPlayer.h"

using aie::SpriteObject;
using aie::TankPlayer;

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    raylib::Texture2D tankSprite("res/tankBody_blue_outline.png");

    TankPlayer Player;
    Player.Sprite = &tankSprite;
    Player.SetLocalPosition(screenWidth / 2, screenHeight / 2);
    
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {   // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        // Update your variables here
        
        float deltaTime = window.GetFrameTime();

        Player.Update(deltaTime);

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);
            
            Player.Draw();
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}