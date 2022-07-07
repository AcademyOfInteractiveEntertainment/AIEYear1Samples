#pragma once
#include "Composite.h"

class Sequence : public Composite
{
protected:	
	virtual ~Sequence();

	virtual void onInitialize();

	virtual Status update(Agent* agent, float deltaTime);

protected:
	Behaviours::iterator m_current;
};

