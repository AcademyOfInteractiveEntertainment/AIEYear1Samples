#include "FollowBehaviour.h"
#include "Agent.h"
#include "NodeMap.h"
#include "raymath.h"

namespace AIForGames
{
    void FollowBehaviour::Enter(Agent* agent)
    {
        // red when following
        agent->SetColor({ 255,0,0,255 });
        agent->Reset();
    }

    void FollowBehaviour::Update(Agent* agent, float deltaTime)
    {
        // check if the agent has moved significantly from its last position
        // if so we want to repath towards it
        Agent* target = agent->GetTarget();

        float dist = Vector2Distance(target->GetPosition(), m_lastTargetPosition);
        if (dist > agent->GetNodeMap()->m_cellSize)
        {
            m_lastTargetPosition = target->GetPosition();
            agent->GoTo(m_lastTargetPosition);
        }
    }

    float FollowBehaviour::Evaluate(Agent* agent)
    {
        Agent* target = agent->GetTarget();
        float dist = Vector2Distance(target->GetPosition(), agent->GetPosition());

        float eval = 10 * agent->GetNodeMap()->m_cellSize - dist;
        if (eval < 0)
            eval = 0;
        return eval;
    }
}
