#include "PathAgent.h"
#include "NodeMap.h"
#include "raymath.h"
#include <iostream>

namespace AIForGames
{
    // for each segment on the path, find the closest point to the player
    // returns the closest point, and the segment index such that point lies between points [segment] and [segment + 1]
    Vector2 PathAgent::GetClosestPointOnPath(int& segment)
    {
        float closestDistance = FLT_MAX;
        Vector2 closestPoint;
        segment = -1;

        // loop over each segment
        for (int i = 1; i < (int)m_path.size(); i++)
        {
            Vector2 segmentStart = m_path[i - 1]->position;
            Vector2 segmentEnd = m_path[i]->position;

            Vector2 toPosition = Vector2Subtract(m_position, segmentStart);
            Vector2 toEnd = Vector2Subtract(segmentEnd, segmentStart);

            // project along the segment to get a value where 0 = level with start and 1 = level with end.
            float alpha = Vector2DotProduct(toPosition, toEnd) / Vector2DotProduct(toEnd, toEnd);

            // clamp that value
            if (alpha < 0) alpha = 0;
            if (alpha > 1) alpha = 1;

            // closest point on the line segment comes from lerping from start to end with our clamped alpha value
            Vector2 point = Vector2Lerp(segmentStart, segmentEnd, alpha);
            float distance = Vector2Distance(point, m_position);

            if (closestDistance > distance)
            {
                closestDistance = distance;
                closestPoint = point;
                segment = i-1;
            }
        }

        return closestPoint;
    }

    // pos is a position on the path, preferably calculated using GetClosestPoint()
    // we step along the path segment by segment until we've reached the end or travelled (distanceAhead) metres
    Vector2 PathAgent::GetPointAlongPath(Vector2 pos, int segment, float distanceAhead)
    {
        Vector2 start = pos;
        Vector2 end = m_path[segment + 1]->position;
        while (distanceAhead > 0)
        {
            float remainingDistance = Vector2Distance(start, end);
            if (distanceAhead <= remainingDistance)
            {
                // we won't reach the end node of this segment with our remaining distance, so lerp towards the end
                return Vector2Lerp(start, end, distanceAhead / remainingDistance);
            }
            else
            {
                distanceAhead -= remainingDistance;
                segment++;
                start = end;
                if (segment + 1 < (int)m_path.size())
                    end = m_path[segment + 1]->position; // move on to the next segment and try again
                else
                    return end; // we've reach the end of the path
            }
        }
        return end;
    }

    void PathAgent::SetNode(Node* node)
    {
        m_currentNode = node;
        m_position = node->position;
    }

    void PathAgent::Update(float deltaTime)
    {
        if (m_path.empty()) return;

        Node* node = m_nodeMap->GetClosestNode(GetPosition());
        if (node)
            m_currentNode = node;

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
            if (m_currentIndex >= (int)m_path.size())
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
        int segment;
        Vector2 closestPoint = GetClosestPointOnPath(segment);
        float distAhead = Vector2Length(m_velocity) * m_lookAhead;
        Vector2 target = GetPointAlongPath(closestPoint, segment, distAhead);

        // find out how far we have to go to the target point
        float dx = target.x - m_position.x;
        float dy = target.y - m_position.y;
        float distanceToNext = sqrtf(dx * dx + dy * dy);

        m_debugPoint1 = closestPoint;
        m_debugPoint2 = target;

        // normalize the vector to the target point
        if (distanceToNext > 0)
        {
            dx /= distanceToNext;
            dy /= distanceToNext;
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

    void PathAgent::DrawDebug()
    {
        DrawCircle((int)m_debugPoint1.x, (int)m_debugPoint1.y, 4, { 255,255,255,255 });
        DrawCircle((int)m_debugPoint2.x, (int)m_debugPoint2.y, 6, { 255,255,255,255 });
    }
}