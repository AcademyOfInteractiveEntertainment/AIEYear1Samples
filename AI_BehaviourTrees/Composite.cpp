#include "Composite.h"
#include <algorithm>

Composite* Composite::add(Behaviour* child)
{
	m_children.push_back(child);
	return this;
}

void Composite::remove(Behaviour* child)
{
	m_children.erase(std::remove(m_children.begin(), m_children.end(), child), m_children.end());
	delete child;
}

void Composite::clear()
{
	for(Behaviours::iterator it = m_children.begin(); it != m_children.end(); it++) {
		delete *it;
	}
	m_children.clear();
}
