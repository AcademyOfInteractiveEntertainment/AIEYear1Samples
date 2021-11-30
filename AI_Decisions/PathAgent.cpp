#include "PathAgent.h"
#include "NodeMap.h"
#include "raymath.h"
#include <iostream>

namespace pathfinding
{
    void PathAgent::SetNode(Node* node)
    {
        currentNode = node;
        position = node->position;
    }

    void PathAgent::Update(float deltaTime)
    {
        if (path.empty()) return;

        if (acceleration == 0)
            UpdateLinear(deltaTime);
        else
            UpdatePhysics(deltaTime);
    }

    void PathAgent::UpdateLinear(float deltaTime)
    {
        // find out how far we have to go to the next node
        float dx = currentNode->position.x - position.x;
        float dy = currentNode->position.y - position.y;
        float distanceToNext = sqrtf(dx * dx + dy * dy);

        // normalize the vector to the next node
        if (distanceToNext > 0)
        {
            dx /= distanceToNext;
            dy /= distanceToNext;
        }

        distanceToNext -= speed * deltaTime;
        if (distanceToNext >= 0)
        {
            // we wont get to the target node this frame - so move linearly towards it
            position.x += dx * speed * deltaTime;
            position.y += dy * speed * deltaTime;
        }
        else
        {
            currentIndex++;
            if (currentIndex >= path.size())
            {
                // we've reached the end, so stop on the node and clear our path
                position.x = currentNode->position.x;
                position.y = currentNode->position.y;
                path.clear();
            }
            else
            {
                // move on to the next node
                Node* oldNode = currentNode;
                currentNode = path[currentIndex];

                // get the unit vector from the old node to the new one
                dx = currentNode->position.x - oldNode->position.x;
                dy = currentNode->position.y - oldNode->position.y;
                float mag = sqrtf(dx * dx + dy * dy);
                dx /= mag;
                dy /= mag;

                // move along the path from the previous node to the new current node by the amount by which we overshot
                // (which is -distanceToNext)
                position.x = oldNode->position.x - distanceToNext * dx;
                position.y = oldNode->position.y - distanceToNext * dy;
            }
        }
    }

    void PathAgent::UpdatePhysics(float deltaTime)
    {
        // find out how far we have to go to the next node
        float dx = currentNode->position.x - position.x;
        float dy = currentNode->position.y - position.y;
        float distanceToNext = sqrtf(dx * dx + dy * dy);

        // normalize the vector to the next node
        if (distanceToNext > 0)
        {
            dx /= distanceToNext;
            dy /= distanceToNext;
        }

        // if we get close enough to the next node, move on
        Vector2 forwards = { 0,0 };
        if (currentIndex > 0)
            forwards = Vector2Normalize(Vector2Subtract(currentNode->position, path[currentIndex - 1]->position));

        if ((forwards.x * dx + forwards.y * dy) * distanceToNext < 1.0f)
            //if (distanceToNext < 16.0f)
        {
            currentIndex++;
            if (currentIndex >= path.size())
                path.clear();
            else
                currentNode = path[currentIndex];
        }

        // friction - we want this to balance out acceleration when we're moving at speed.
        // so this should provide a force equal to -acceleration when moving at top speed.
        float damping = Vector2Length(velocity) / speed;
        std::cout << "Damping = " << damping  << ", Speed = " << Vector2Length(velocity) << std::endl;
        if (damping > 1.0f)
            damping = 1;
        velocity = Vector2Add(velocity, Vector2Scale(velocity, -acceleration / speed * deltaTime));

        // accelerate towards target point
        velocity.x += acceleration * deltaTime * dx;
        velocity.y += acceleration * deltaTime * dy;

        // apply velocity
        position = Vector2Add(position, Vector2Scale(velocity, deltaTime));
    }

    void PathAgent::GoToNode(Node* node)
    {
        path = DijkstrasSearch(currentNode, node);
        path = nodeMap->SmoothPath(path);
        currentIndex = 0;
    }
}