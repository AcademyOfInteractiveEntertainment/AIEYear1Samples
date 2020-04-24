#ifndef CIRCLE_H
#define CIRCLE_H

#include <raylib.h>

class Circle
{
public:
	Circle(Vector2 position, float radius);
	~Circle();

	Vector2 m_position;
	
	float m_radius;

private:
	Circle();
};

#endif