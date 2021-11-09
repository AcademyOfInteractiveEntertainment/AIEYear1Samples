#pragma once
#include "Behaviour.h"

namespace pathfinding
{
    class GotoPointBehaviour : public Behaviour
    {
    public:
        virtual void Update(Agent* agent, float deltaTime);
    };
}
