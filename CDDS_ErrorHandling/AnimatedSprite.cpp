#include "AnimatedSprite.h"
#include <assert.h>
#include <iostream>
#include <exception>
#include <string>

AnimatedSprite::AnimatedSprite() : m_currentFrame(0), m_timer(0)
{
}


AnimatedSprite::~AnimatedSprite()
{
	// not the best design choice, since textures can't be reused in multiple animations
	for (Frame f : m_frames) {
		UnloadTexture(f.m_texture);
	}
}

int AnimatedSprite::AddFrame(Texture2D texture, float delay)
{
	m_frames.push_back(Frame(texture, delay));
	return NO_ERROR;
}


void AnimatedSprite::Update(float deltaTime)
{
	m_timer += deltaTime;

	if (m_timer >= m_frames.at(m_currentFrame).m_delay) {
		m_timer -= m_frames.at(m_currentFrame).m_delay;
		m_currentFrame++;
		if (m_currentFrame >= m_frames.size())
			m_currentFrame = 0;
	}
}

void AnimatedSprite::Draw(int x, int y, int flags)
{
	Frame frame = m_frames.at(m_currentFrame);

	switch (flags) {
	case 0: {
		DrawTexture(frame.m_texture, x, y, WHITE);
		break;
	}
	case DRAW_FLIP_X: {
		DrawTextureRec(frame.m_texture, Rectangle{ 0, 0, (float)frame.m_texture.width, (float)-frame.m_texture.height }, Vector2{ (float)x, (float)y }, WHITE);
		break;
	}
	case DRAW_FLIP_Y: {
		DrawTextureRec(frame.m_texture, Rectangle{ 0, 0, (float)-frame.m_texture.width, (float)frame.m_texture.height }, Vector2{ (float)x, (float)y }, WHITE);
		break;
	}
	case DRAW_FLIP_X | DRAW_FLIP_Y: {
		DrawTextureRec(frame.m_texture, Rectangle{ 0, 0, (float)-frame.m_texture.width, (float)-frame.m_texture.height }, Vector2{ (float)x, (float)y }, WHITE);
		break;
	}
	default:
		//assert(0);
		//assert(!"Invalid flag value");
		throw std::exception((std::string("Invalid flag value: ") + std::to_string(flags)).c_str());
	}
}