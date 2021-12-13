#pragma once
#include "Condition.h"

namespace AIForGames
{
	class DistanceCondition : public Condition
	{
	private:
		float m_distance;
		bool m_lessThan;

	public:
		DistanceCondition(float d, bool lt) : m_distance(d), m_lessThan(lt) {}
		virtual bool IsTrue(Agent* agent);
	};
}