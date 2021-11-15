#include "State.h"
#include "Condition.h"
#include "FiniteStateMachine.h"

namespace pathfinding
{
    FiniteStateMachine::~FiniteStateMachine()
    {
        // the FSM owns every Condition and Behaviour pair assigned to it
        for (State* s : m_states)
            delete s;
    }

    void FiniteStateMachine::Enter(Agent* agent)
    {
        m_currentState->Enter(agent);
    }

    void FiniteStateMachine::Update(Agent* agent, float deltaTime)
    {
        // check the current state's transitions
        for (State::Transition t : m_currentState->GetTransitions())
        {
            if (t.condition->IsTrue(agent))
               m_newState = t.targetState;
        }

        // if we've changed state, clean up the old one and initialise the new one
        if (m_newState != nullptr && m_newState != m_currentState)
        {
            m_currentState->Exit(agent);
            m_currentState = m_newState;
            m_currentState->Enter(agent);
        }

        // update the current state
        m_currentState->Update(agent, deltaTime);
    }
}


