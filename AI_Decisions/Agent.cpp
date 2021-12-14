#include "Agent.h"
#include "NodeMap.h"

namespace AIForGames
{
    Agent::Agent(NodeMap* nodeMap, Behaviour* behaviour) : m_current(behaviour), m_nodeMap(nodeMap), m_color({ 255, 255, 0, 255 })
    {
        m_pathAgent.SetNodeMap(nodeMap);
        m_current->Enter(this);
        m_target = nullptr;
    }

    Agent::~Agent()
    {
        delete m_current;
    }

    void Agent::Update(float deltaTime)
    {
        if (m_current)
            m_current->Update(this, deltaTime);
        m_pathAgent.Update(deltaTime);
    }

    void Agent::Draw()
    {
        DrawCircle((int)m_pathAgent.GetPosition().x, (int)m_pathAgent.GetPosition().y, 8, m_color);
        m_pathAgent.DrawDebug();
    }

    void Agent::GoTo(Vector2 point)
    {
        Node* end = m_nodeMap->GetClosestNode(point);
        m_pathAgent.GoToNode(end);
    }

    void Agent::GoTo(Node* node)
    {
        m_pathAgent.GoToNode(node);
    }

    void Agent::SetNode(Node* node)
    {
        m_pathAgent.SetNode(node);
    }

    bool Agent::PathComplete()
    {
        return m_pathAgent.GetPath().empty();
    }
}