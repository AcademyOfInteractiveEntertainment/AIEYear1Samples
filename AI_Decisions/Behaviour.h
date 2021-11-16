#pragma once
namespace pathfinding
{
	class Agent;

    // abstract base class for all actions
    class Behaviour
    {
    public:
        virtual void Enter(Agent* agent) {}
        virtual void Update(Agent* agent, float deltaTime) = 0;
        virtual void Exit(Agent* agent) {}

        // used by UtilityAI to determine which behaviour to do
        virtual float Evaluate(Agent* agent) { return 0.0f; }
    };
}
