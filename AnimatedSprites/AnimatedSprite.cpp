#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite() : m_currentFrame(0), m_timer(0)
{
}


AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::AddFrame(Texture2D texture, float delay)
{
	m_frames.push_back(Frame(texture, delay));
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

void AnimatedSprite::Draw(int x, int y)
{
	Frame frame = m_frames.at(m_currentFrame);
	DrawTexture(frame.m_texture, x, y, WHITE);
}