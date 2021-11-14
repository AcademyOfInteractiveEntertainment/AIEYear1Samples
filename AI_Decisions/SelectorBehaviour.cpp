#include "SelectorBehaviour.h"
#include "Agent.h"
#include "NodeMap.h"
#include "raymath.h"

namespace pathfinding
{
    SelectorBehaviour::~SelectorBehaviour()
    {
        delete b1;
        delete b2;
    }

    void SelectorBehaviour::Update(Agent* agent, float deltaTime)
    {
        if (Vector2Distance(agent->GetPosition(), agent->GetTarget()->GetPosition()) < agent->GetNodeMap()->cellSize * 5)
        {
            SetBehaviour(b1, agent);
            agent->SetColor({ 255, 0, 0, 255 }); //red
        }
        else
        {
            SetBehaviour(b2, agent);
            agent->SetColor({ 0, 255, 255, 255 }); // cyan
        }
        selected->Update(agent, deltaTime);
    }

    void SelectorBehaviour::SetBehaviour(Behaviour* b, Agent* agent)
    {
        if (selected != b)
        {
            selected = b;
            agent->Reset();
        }
    }
}