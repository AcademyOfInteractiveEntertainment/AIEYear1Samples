#include "Circle.h"

Circle::Circle()
{
	m_position.x = 0.0f;
	m_position.y = 0.0f;
	m_radius	= 1.0f;
}

Circle::Circle(Vector2 a_position, float a_radius)
{
	m_position = a_position;
	m_radius	= a_radius;
}

Circle::~Circle()
{

}
