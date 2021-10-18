#include "PathAgent.h"

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

                // get the unit vectore from the old node to the new one
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

    void PathAgent::GoToNode(Node* node)
    {
        path = DijkstrasSearch(currentNode, node);
        currentIndex = 0;
    }

    void PathAgent::Draw()
    {
        DrawCircle(position.x, position.y, 8, { 255,255,0,255 });
    }
}