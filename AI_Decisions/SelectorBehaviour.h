#pragma once
#include "Behaviour.h"

namespace AIForGames
{
    class SelectorBehaviour : public Behaviour
    {
    private:
        Behaviour* m_b1;
        Behaviour* m_b2;
        Behaviour* m_selected;

        void SetBehaviour(Behaviour* b, Agent* agent);

    public:
        SelectorBehaviour(Behaviour* _b1, Behaviour* _b2) : m_b1(_b1), m_b2(_b2), m_selected(nullptr) {}
        ~SelectorBehaviour();

        virtual void Update(Agent* agent, float deltaTime);
    };
}

