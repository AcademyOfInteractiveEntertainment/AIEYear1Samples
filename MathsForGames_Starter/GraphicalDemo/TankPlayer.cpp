#include "TankPlayer.h"

namespace aie
{
	void TankPlayer::OnUpdate(float deltaTime)
	{
        const float MOVESPEED = 150.0f;
        const float ROTSPEED = 2.0f;
        const float SCLSPEED = 5.0f;
        
        const float TURRET_ROTSPEED = 1.0f;

        //
        // check for key input 
        //
        float yMove = 0.0f;

        // W-S for UP-DOWN movement
        if (IsKeyDown(KeyboardKey::KEY_W))
        {
            yMove += MOVESPEED;
        }
        if (IsKeyDown(KeyboardKey::KEY_S))
        {
            yMove -= MOVESPEED;
        }

        Vector3 finalMove = GetForward() * (yMove * deltaTime);

        // apply the move!
        Translate(finalMove);
	}
}
