#include "SelectorBehaviour.h"
#include "Agent.h"
#include "NodeMap.h"
#include "raymath.h"

namespace pathfinding
{
    void SelectorBehaviour::Update(Agent* agent, float deltaTime)
    {
        Behaviour* selected;

        if (Vector2Distance(agent->GetPosition(), agent->GetTarget()->GetPosition()) < agent->GetNodeMap()->cellSize * 5)
        {
            selected = b1;
            agent->SetColor({ 255, 0, 0, 255 });
        }
        else
        {
            selected = b2;
            agent->SetColor({ 0, 255, 255, 255 });
        }
        selected->Update(agent, deltaTime);
    }
}