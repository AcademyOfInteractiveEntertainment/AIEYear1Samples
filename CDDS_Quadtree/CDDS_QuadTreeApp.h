#pragma once
#include "Quadtree.h"

class CDDS_QuadTreeApp {
public:

	CDDS_QuadTreeApp();
	virtual ~CDDS_QuadTreeApp();

	virtual bool Startup();
	virtual void Shutdown();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:
	Quadtree m_quadtree;
	Texture2D m_rock;
};