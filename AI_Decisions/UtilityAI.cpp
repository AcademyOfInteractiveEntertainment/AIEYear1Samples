#include "UtilityAI.h"

namespace AIForGames
{
    UtilityAI::~UtilityAI()
    {
        for (Behaviour* b : m_behaviours)
            delete b;
    }

    void UtilityAI::Update(Agent* agent, float deltaTime)
    {
        float bestEval = 0;
        Behaviour* newBehaviour = nullptr;
        for (Behaviour* b : m_behaviours)
        {
            float eval = b->Evaluate(agent);
            if (eval > bestEval)
            {
                bestEval = eval;
                newBehaviour = b;
            }
        }

        if (newBehaviour != nullptr 
            && newBehaviour != m_currentBehaviour)
        {
            if (m_currentBehaviour)
                m_currentBehaviour->Exit(agent);
            m_currentBehaviour = newBehaviour;
            m_currentBehaviour->Enter(agent);
        }

        m_currentBehaviour->Update(agent, deltaTime);
    }
}
