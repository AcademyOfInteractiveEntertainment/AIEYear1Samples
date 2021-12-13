#pragma once
#include <vector>
#include "Behaviour.h"

namespace AIForGames
{
    class Agent;

    class UtilityAI :public Behaviour
    {
    private:
        std::vector<Behaviour*> m_behaviours;
        Behaviour* m_currentBehaviour;

    public:
        ~UtilityAI();

        virtual void Update(Agent* agent, float deltaTime);
        void AddBehaviour(Behaviour* b) { m_behaviours.push_back(b); }
    };
}
