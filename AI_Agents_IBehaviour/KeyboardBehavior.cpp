#include "KeyboardBehavior.h"
#include "Agent.h"
#include "raylib.h"

KeyboardBehavior::KeyboardBehavior()
{

}

KeyboardBehavior::~KeyboardBehavior()
{

}

void KeyboardBehavior::Update(float a_deltaTime, MovementInfo& a_movementInfo)
{
	// If either W or S is pressed apply a force to the acceleration
	if (IsKeyDown(KEY_W))
	{
		a_movementInfo.m_acceleration.y -= a_movementInfo.m_maxSpeed * a_deltaTime;
	}
	if (IsKeyDown(KEY_S))
	{
		a_movementInfo.m_acceleration.y += a_movementInfo.m_maxSpeed * a_deltaTime;
	}
	// if neither are pressed then reduce the acceleration
	if (!(IsKeyDown(KEY_W)) && !(IsKeyDown(KEY_S)))
	{
		a_movementInfo.m_velocity.y -= a_movementInfo.m_velocity.y * a_deltaTime;
	}

	// If either A or D is pressed apply a force to the acceleration
	if (IsKeyDown(KEY_A))
	{
		a_movementInfo.m_acceleration.x -= a_movementInfo.m_maxSpeed * a_deltaTime;
	}
	if (IsKeyDown(KEY_D))
	{
		a_movementInfo.m_acceleration.x += a_movementInfo.m_maxSpeed * a_deltaTime;
	}
	// if neither are pressed then reduce the acceleration
	if (!(IsKeyDown(KEY_A)) && !(IsKeyDown(KEY_D)))
	{
		a_movementInfo.m_velocity.x -= a_movementInfo.m_velocity.x * a_deltaTime;
	}
}