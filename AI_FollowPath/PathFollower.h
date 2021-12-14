#pragma once
#include <vector>
#include "raymath.h"

class PathFollower
{
public:
	PathFollower();

	// array of points describing a closed path
	std::vector<Vector2> m_path;
	Vector2 m_position;
	Vector2 m_velocity;
	float m_speed;
	float m_acceleration;

	Vector2 m_debugPoint1;
	Vector2 m_debugPoint2;

	Vector2 GetClosestPointOnPath(int& segment);
	Vector2 GetPointAlongPath(Vector2 pos, int segment, float distanceAhead);

	void Update(float deltaTime);
	void Draw();
};

