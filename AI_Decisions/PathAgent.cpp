#include "PathAgent.h"
#include "NodeMap.h"
#include "raymath.h"
#include <iostream>

namespace AIForGames
{
    void PathAgent::SetNode(Node* node)
    {
        m_currentNode = node;
        m_position = node->position;
    }

    void PathAgent::Update(float deltaTime)
    {
        if (m_path.empty()) return;

        if (m_acceleration == 0)
            UpdateLinear(deltaTime);
        else
            UpdatePhysics(deltaTime);
    }

    void PathAgent::UpdateLinear(float deltaTime)
    {
        // find out how far we have to go to the next node
        float dx = m_currentNode->position.x - m_position.x;
        float dy = m_currentNode->position.y - m_position.y;
        float distanceToNext = sqrtf(dx * dx + dy * dy);

        // normalize the vector to the next node
        if (distanceToNext > 0)
        {
            dx /= distanceToNext;
            dy /= distanceToNext;
        }

        distanceToNext -= m_speed * deltaTime;
        if (distanceToNext >= 0)
        {
            // we wont get to the target node this frame - so move linearly towards it
            m_position.x += dx * m_speed * deltaTime;
            m_position.y += dy * m_speed * deltaTime;
        }
        else
        {
            m_currentIndex++;
            if (m_currentIndex >= m_path.size())
            {
                // we've reached the end, so stop on the node and clear our path
                m_position.x = m_currentNode->position.x;
                m_position.y = m_currentNode->position.y;
                m_path.clear();
            }
            else
            {
                // move on to the next node
                Node* oldNode = m_currentNode;
                m_currentNode = m_path[m_currentIndex];

                // get the unit vector from the old node to the new one
                dx = m_currentNode->position.x - oldNode->position.x;
                dy = m_currentNode->position.y - oldNode->position.y;
                float mag = sqrtf(dx * dx + dy * dy);
                dx /= mag;
                dy /= mag;

                // move along the path from the previous node to the new current node by the amount by which we overshot
                // (which is -distanceToNext)
                m_position.x = oldNode->position.x - distanceToNext * dx;
                m_position.y = oldNode->position.y - distanceToNext * dy;
            }
        }
    }

    void PathAgent::UpdatePhysics(float deltaTime)
    {
        // find out how far we have to go to the next node
        float dx = m_currentNode->position.x - m_position.x;
        float dy = m_currentNode->position.y - m_position.y;
        float distanceToNext = sqrtf(dx * dx + dy * dy);

        // normalize the vector to the next node
        if (distanceToNext > 0)
        {
            dx /= distanceToNext;
            dy /= distanceToNext;
        }

        // if we get close enough to the next node, move on
        Vector2 forwards = { 0,0 };
        if (m_currentIndex > 0)
            forwards = Vector2Normalize(Vector2Subtract(m_currentNode->position, m_path[m_currentIndex - 1]->position));

        if ((forwards.x * dx + forwards.y * dy) * distanceToNext < 1.0f)
            //if (distanceToNext < 16.0f)
        {
            m_currentIndex++;
            if (m_currentIndex >= m_path.size())
                m_path.clear();
            else
                m_currentNode = m_path[m_currentIndex];
        }

        // friction - we want this to balance out acceleration when we're moving at speed.
        // so this should provide a force equal to -acceleration when moving at top speed.
        float damping = Vector2Length(m_velocity) / m_speed;
        std::cout << "Damping = " << damping  << ", Speed = " << Vector2Length(m_velocity) << std::endl;
        if (damping > 1.0f)
            damping = 1;
        m_velocity = Vector2Add(m_velocity, Vector2Scale(m_velocity, -m_acceleration / m_speed * deltaTime));

        // accelerate towards target point
        m_velocity.x += m_acceleration * deltaTime * dx;
        m_velocity.y += m_acceleration * deltaTime * dy;

        // apply velocity
        m_position = Vector2Add(m_position, Vector2Scale(m_velocity, deltaTime));
    }

    void PathAgent::GoToNode(Node* node)
    {
        m_path = DijkstrasSearch(m_currentNode, node);
        m_path = m_nodeMap->SmoothPath(m_path);
        m_currentIndex = 0;
    }
}