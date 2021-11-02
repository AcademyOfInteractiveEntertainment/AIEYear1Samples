#include "raylib.h"
#include "Agent.h"
#include "GotoPointBehaviour.h"

namespace pathfinding
{
    void GotoPointBehaviour::Do(Agent* agent)
    {
        // read mouseclicks, left for start node, end for right node
        if (IsMouseButtonPressed(0))
        {
            Vector2 mousePos = GetMousePosition();
            agent->GoTo(mousePos);
        }
    }
}
