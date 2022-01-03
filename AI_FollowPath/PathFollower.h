#pragma once
#include <vector>
#include <glm/glm.hpp>

class PathFollower
{
public:
    PathFollower();
    void Update(float deltaTime);
    void Draw();

    void AddPoint(glm::vec2 point) { m_path.push_back(point); }
    void SetPosition(float x, float y) { m_position.x = x; m_position.y = y; }

private:
    // array of points describing a closed path
    std::vector<glm::vec2> m_path;
    glm::vec2 m_position;
    glm::vec2 m_velocity;
    float m_speed;
    float m_acceleration;

    glm::vec2 m_debugClosest;
    glm::vec2 m_debugTarget;

    glm::vec2 GetClosestPointOnPath(int& segment);
    glm::vec2 GetPointAlongPath(glm::vec2 pos, int segment, float distanceAhead);
};

