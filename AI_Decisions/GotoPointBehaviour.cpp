#include "raylib.h"
#include "Agent.h"
#include "GotoPointBehaviour.h"

namespace pathfinding
{
    void GotoPointBehaviour::Update(Agent* agent, float deltaTime)
    {
        // read mouseclicks, left for start node, end for right node
        if (IsMouseButtonPressed(0))
        {
            Vector2 mousePos = GetMousePosition();
            agent->GoTo(mousePos);
        }
    }
}
