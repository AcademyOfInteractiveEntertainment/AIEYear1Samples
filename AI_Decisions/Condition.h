#pragma once
#include "Agent.h"

namespace AIForGames
{
	class Condition
	{
	public:
		virtual bool IsTrue(Agent* agent) = 0;
	};
}