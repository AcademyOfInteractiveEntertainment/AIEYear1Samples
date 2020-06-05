#pragma once
#include "AABB.h"

class GameObject;

class Quadtree
{
public:
	static const int m_capacity = 2;

	enum SUBTREE {
		TOP_LEFT = 0,
		TOP_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_RIGHT
	};

public:
	Quadtree();
	Quadtree(AABB boundary);

	~Quadtree();

	bool Insert(GameObject*);
	void Subdivide();

	void Update(float deltaTime);
	void Draw();

private:
	Quadtree** m_children;

	AABB m_boundary;
		
	GameObject** m_objects;
};
