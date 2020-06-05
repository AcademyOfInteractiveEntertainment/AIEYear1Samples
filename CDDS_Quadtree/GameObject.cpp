#include "GameObject.h"

GameObject::GameObject(Texture2D* texture, Vector2 position)
{
	m_texture = texture;

	m_bounds.m_centre = position;
	m_bounds.m_halfSize.x = m_texture->height >> 1;
	m_bounds.m_halfSize.y = m_texture->width >> 1;
}


GameObject::~GameObject()
{
}

void GameObject::Update(float deltaTime)
{

}

void GameObject::Draw()
{	
	DrawTexture(*m_texture, m_bounds.m_centre.x, m_bounds.m_centre.y, WHITE);
}