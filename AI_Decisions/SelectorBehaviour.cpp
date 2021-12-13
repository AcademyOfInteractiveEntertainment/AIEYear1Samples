#include "SelectorBehaviour.h"
#include "Agent.h"
#include "NodeMap.h"
#include "raymath.h"

namespace AIForGames
{
    SelectorBehaviour::~SelectorBehaviour()
    {
        delete m_b1;
        delete m_b2;
    }

    void SelectorBehaviour::Update(Agent* agent, float deltaTime)
    {
        if (Vector2Distance(agent->GetPosition(), agent->GetTarget()->GetPosition()) < agent->GetNodeMap()->m_cellSize * 5)
        {
            SetBehaviour(m_b1, agent);
            agent->SetColor({ 255, 0, 0, 255 }); //red
        }
        else
        {
            SetBehaviour(m_b2, agent);
            agent->SetColor({ 0, 255, 255, 255 }); // cyan
        }
        m_selected->Update(agent, deltaTime);
    }

    void SelectorBehaviour::SetBehaviour(Behaviour* b, Agent* agent)
    {
        if (m_selected != b)
        {
            m_selected = b;
            agent->Reset();
        }
    }
}