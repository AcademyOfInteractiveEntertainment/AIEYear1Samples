#pragma once
#include "Behaviour.h"

namespace AIForGames
{
    class GotoPointBehaviour : public Behaviour
    {
    public:
        virtual void Update(Agent* agent, float deltaTime);
    };
}
