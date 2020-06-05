#pragma once
#include <vector>
#include "raylib.h"

class AnimatedSprite
{
private:
	struct Frame {
		Texture2D m_texture;
		float m_delay;
		Frame(Texture2D texture, float delay) : m_texture(texture), m_delay(delay) {}
	};

public:
	AnimatedSprite();
	~AnimatedSprite();

	void AddFrame(Texture2D texture, float delay);

	void Update(float deltaTime);
	void Draw(int x, int y);

private:
	std::vector<Frame> m_frames;
	int m_currentFrame;
	float m_timer;
};

