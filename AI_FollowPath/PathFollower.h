#pragma once
#include <vector>
#include "raymath.h"

class PathFollower
{
public:
    PathFollower();
    void Update(float deltaTime);
    void Draw();

    void AddPoint(Vector2 point) { m_path.push_back(point); }
    void SetPosition(float x, float y) { m_position.x = x; m_position.y = y; }

private:
    // array of points describing a closed path
    std::vector<Vector2> m_path;
    Vector2 m_position;
    Vector2 m_velocity;
    float m_speed;
    float m_acceleration;

    Vector2 m_debugClosest;
    Vector2 m_debugTarget;

    Vector2 GetClosestPointOnPath(int& segment);
    Vector2 GetPointAlongPath(Vector2 pos, int segment, float distanceAhead);
};

