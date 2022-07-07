#pragma once
#include "Composite.h"

class Selector : public Composite
{
protected:
	virtual ~Selector();

	virtual void onInitialize();

	virtual Status update(Agent* agent, float deltaTime);

protected:
	Behaviours::iterator m_current;
};

