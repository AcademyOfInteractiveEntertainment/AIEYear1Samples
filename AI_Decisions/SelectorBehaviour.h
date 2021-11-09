#pragma once
#include "Behaviour.h"

namespace pathfinding
{
    class SelectorBehaviour : public Behaviour
    {
    private:
        Behaviour* b1;
        Behaviour* b2;

    public:
        SelectorBehaviour(Behaviour* _b1, Behaviour* _b2) : b1(_b1), b2(_b2) {}
        virtual void Update(Agent* agent, float deltaTime);
    };
}

