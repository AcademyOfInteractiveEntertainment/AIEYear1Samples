#pragma once
#include "Agent.h"

namespace pathfinding
{
	class Condition
	{
	public:
		virtual bool IsTrue(Agent* agent) = 0;
	};
}