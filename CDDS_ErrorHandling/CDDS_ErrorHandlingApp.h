#pragma once

#include "AnimatedSprite.h"

struct Vector2D {
	float x;
	float y;
};

class CDDS_ErrorHandlingApp {
public:

	CDDS_ErrorHandlingApp();
	~CDDS_ErrorHandlingApp();

	bool Startup();
	void Shutdown();

	void Update(float deltaTime);
	void Draw();

protected:
	AnimatedSprite		m_sprite;
	Vector2D			m_position;
};