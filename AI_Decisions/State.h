#pragma once
#include <vector>

namespace pathfinding
{
    // forward declarations - we only use pointers to these classes here, so we dont need full includes
    class Behaviour;
    class Condition;
    class Agent;

    class State
    {
    public:
        struct Transition
        {
            Condition* condition;
            State* targetState;
        };

    private:
        std::vector<Behaviour*> m_behaviours;
        std::vector<Transition> m_transitions;

    public:
        State();
        State(Behaviour* b) { m_behaviours.push_back(b); }
        ~State();
        void AddBehaviour(Behaviour* b) { m_behaviours.push_back(b); }
        void AddTransition(Condition* condition, State* targetState);

        const std::vector<Transition>& GetTransitions() { return m_transitions; }

        virtual void Enter(Agent* agent);
        virtual void Update(Agent* agent, float deltaTime);
        virtual void Exit(Agent* agent);
    };
}