#pragma once
#include <vector>
#include "raylib.h"

const int DRAW_FLIP_X = 0x01;
const int DRAW_FLIP_Y = 0x04;	// I know, the next bit is x02. This is used to demonstrate an assert in some cases

const int NO_ERROR = 0;
const int ERROR_NULL_TEXTURE = -1;
const int ERROR_NO_PIXEL_DATA = -2;

namespace aie {
	class Renderer2D;
};

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

	int AddFrame(Texture2D texture, float delay);

	void Update(float deltaTime);
	void Draw(int x, int y, int flags = 0);

	int GetCurrentFrame() { return m_currentFrame; }
	int GetFrameCount() { return m_frames.size(); }

private:
	std::vector<Frame> m_frames;
	int m_currentFrame;
	float m_timer;
};

