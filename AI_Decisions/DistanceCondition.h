#pragma once
#include "Condition.h"

namespace pathfinding
{
	class DistanceCondition : public Condition
	{
	private:
		float distance;
		bool lessThan;

	public:
		DistanceCondition(float d, bool lt) : distance(d), lessThan(lt) {}
		virtual bool IsTrue(Agent* agent);
	};
}