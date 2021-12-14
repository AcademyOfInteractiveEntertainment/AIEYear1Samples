#include "PathFollower.h"

PathFollower::PathFollower()
{
	m_position.x = 0;
	m_position.y = 0;

	m_velocity.x = 0;
	m_velocity.y = 0;

	m_speed = 32;
	m_acceleration = 320;
}

void PathFollower::Update(float deltaTime)
{
	int segment;
	Vector2 closestPoint = GetClosestPointOnPath(segment);
	float distAhead = Vector2Length(m_velocity);
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

	// calculate our desired topspeed and reduce it if we're approaching a bend
	float topSpeed = m_speed;

	if (segment >= 0)
	{
		Vector2 localForwards = Vector2Normalize(Vector2Subtract(m_path[segment + 1], m_path[segment]));
		Vector2 toTarget = Vector2Normalize(Vector2Subtract(target, m_position));
		float braking = Vector2DotProduct(localForwards, toTarget);
		if (braking < 0.1f)
			braking = 0.1f;
		topSpeed *= braking;
	}

	// friction - we want this to balance out acceleration when we're moving at speed.
	// so this should provide a force equal to -acceleration when moving at top speed.
	float damping = Vector2Length(m_velocity) / m_speed;
	if (damping > 1.0f)
		damping = 1;
	m_velocity = Vector2Add(m_velocity, Vector2Scale(m_velocity, -m_acceleration / topSpeed * deltaTime));

	// accelerate towards target point
	m_velocity.x += m_acceleration * deltaTime * dx;
	m_velocity.y += m_acceleration * deltaTime * dy;

	// apply velocity
	m_position = Vector2Add(m_position, Vector2Scale(m_velocity, deltaTime));
}

void PathFollower::Draw()
{
	// draw the path in black
	for (int i = 0; i < (int)m_path.size(); i++)
	{
		Vector2 start = m_path[i == 0 ? (int)m_path.size() - 1 : i - 1];
		Vector2 end = m_path[i];
		DrawLine((int)start.x, (int)start.y, (int)end.x, (int)end.y, { 0,0,0,255 });
		DrawCircle((int)start.x, (int)start.y, 4, { 0,0,0,255 });
	}

	// draw the agent as a blue circle
	DrawCircle((int)m_position.x, (int)m_position.y, 8, { 0,0,255,255 });

	// draw debug points
	DrawCircle((int)m_debugPoint1.x, (int)m_debugPoint1.y, 4, { 128,128,128,255 });
	DrawCircle((int)m_debugPoint2.x, (int)m_debugPoint2.y, 6, { 128,128,128,255 });
}



// for each segment on the path, find the closest point to the player
// returns the closest point, and the segment index such that point lies between points [segment] and [segment + 1]
Vector2 PathFollower::GetClosestPointOnPath(int& segment)
{
	float closestDistance = FLT_MAX;
	Vector2 closestPoint = m_position;
	segment = -1;

	// loop over each segment
	for (int i = 1; i < (int)m_path.size(); i++)
	{
		Vector2 segmentStart = m_path[i - 1];
		Vector2 segmentEnd = m_path[i];

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
			segment = i - 1;
		}
	}

	return closestPoint;
}

// pos is a position on the path, preferably calculated using GetClosestPoint()
// we step along the path segment by segment until we've reached the end or travelled (distanceAhead) metres
Vector2 PathFollower::GetPointAlongPath(Vector2 pos, int segment, float distanceAhead)
{
	Vector2 start = pos;
	Vector2 end = m_path[segment + 1];
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
			if (segment + 1 >= (int)m_path.size())
				segment = -1;
			end = m_path[segment + 1]; // move on to the next segment and try again
		}
	}
	return end;
}


