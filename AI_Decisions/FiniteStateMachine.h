#pragma once
#include <vector>
#include "Behaviour.h"

namespace pathfinding
{
    class State;
    class Agent;
    
    class FiniteStateMachine : public Behaviour
    {
    private:
        std::vector<State*> m_states;

        State* m_currentState;
        State* m_newState;

    public:
        FiniteStateMachine(State* s) : m_currentState(s), m_newState(nullptr) {}
        virtual ~FiniteStateMachine();
        void AddState(State* s) { m_states.push_back(s); }

        void Enter(Agent* agent);
        void Update(Agent* agent, float deltaTime);
    };
}
