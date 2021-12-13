#include "WanderBehaviour.h"
#include "Agent.h"
#include "NodeMap.h"
#include <raymath.h>

namespace AIForGames
{
    void WanderBehaviour::Enter(Agent* agent)
    {
        // cyan when wandering
        agent->SetColor({ 0,255,255,255 });

        agent->Reset();
    }

    void WanderBehaviour::Update(Agent* agent, float deltaTime)
    {
        if (agent->PathComplete())
        {
            Node* node = agent->GetNodeMap()->GetRandomNode();
            agent->GoTo(node);
        }
    }
    float WanderBehaviour::Evaluate(Agent* agent)
    {
        Agent* target = agent->GetTarget();
        float dist = Vector2Distance(target->GetPosition(), agent->GetPosition());

        float eval = dist;
        if (eval < 0)
            eval = 0;
        return eval;
    }
}