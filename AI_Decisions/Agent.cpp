#include "Agent.h"
#include "NodeMap.h"

namespace pathfinding
{
    Agent::~Agent()
    {
        delete current;
    }

    void Agent::Update(float deltaTime)
    {
        if (current)
            current->Update(this, deltaTime);
        pathAgent.Update(deltaTime);
    }

    void Agent::Draw()
    {
        DrawCircle(pathAgent.position.x, pathAgent.position.y, 8, color);
    }

    void Agent::GoTo(Vector2 point)
    {
        Node* end = nodeMap->GetClosestNode(point);
        pathAgent.GoToNode(end);
    }

    void Agent::GoTo(Node* node)
    {
        pathAgent.GoToNode(node);
    }

    void Agent::SetNode(Node* node)
    {
        pathAgent.SetNode(node);
    }

    bool Agent::PathComplete()
    {
        return pathAgent.path.empty();
    }
}