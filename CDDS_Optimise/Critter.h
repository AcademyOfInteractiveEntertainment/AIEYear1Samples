#pragma once


#include "raylib.h"

class Critter
{
protected:	
	Vector2 m_position;
	Vector2 m_velocity;
	float m_radius;

	Texture2D m_texture;

	bool m_isLoaded;
	bool m_isDirty;		// indicates if we've already processed a collision response for this critter
	
public:
	Critter();
	~Critter();

	void Init(Vector2 position, Vector2 velocity, float radius, const char* texture);
	void Destroy();
	void Update(float dt);
	void Draw();

	float GetX() { return m_position.x; }
	float GetY() { return m_position.y; }
	void SetX(float x) { m_position.x = x; }
	void SetY(float y) { m_position.y = y; }

	Vector2 GetPosition() { return m_position; }
	void SetPosition(Vector2 position) { m_position = position; }

	Vector2 GetVelocity() { return m_velocity; }
	void SetVelocity(Vector2 velocity) { m_velocity = velocity; }

	float GetRadius() { return m_radius; }

	bool IsDirty() { return m_isDirty; }
	void SetDirty() { m_isDirty = true; }

	bool IsDead() { return m_isLoaded == false; }

};

