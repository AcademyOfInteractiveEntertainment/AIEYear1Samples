#pragma once
#include "Behaviour.h"

namespace pathfinding
{
	class GotoPointBehaviour : public Behaviour
	{
	public:
		virtual void Do(Agent* agent);
	};
}
