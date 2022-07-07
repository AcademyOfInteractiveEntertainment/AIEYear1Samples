#include "Sequence.h"

Sequence::~Sequence()
{
	clear();
}

void Sequence::onInitialize()
{
	m_current = m_children.begin();
}

Status Sequence::update(Agent* agent, float deltaTime)
{
	// Keep going until a child behavior says it's running.
    while(true)
    {
        Status s = (*m_current)->tick(agent, deltaTime);

        // If the child fails, or keeps running, do the same.
        if (s != BH_SUCCESS)
        {
            return s;
        }

        // Hit the end of the array, job done!
        if (++m_current == m_children.end())
        {
            return BH_SUCCESS;
        }
    }
}