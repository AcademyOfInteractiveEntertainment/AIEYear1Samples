#pragma once
#include <vector>
#include "Behaviour.h"

namespace AIForGames
{
    class State;
    class Agent;
    
    class FiniteStateMachine : public Behaviour
    {
    private:
        std::vector<State*> m_states;

        State* m_currentState;

    public:
        FiniteStateMachine(State* s) : m_currentState(s) {}
        virtual ~FiniteStateMachine();
        void AddState(State* s) { m_states.push_back(s); }

        void Enter(Agent* agent);
        void Update(Agent* agent, float deltaTime);
    };
}
