#include "BlackboardAgent.h"


float BlackboardAgent::EvaluateResponse(BlackboardQuestion* question, Blackboard* blackboard) {

	NeedHelpQuestion* q = (NeedHelpQuestion*)question;

	bool requireHelp = false;
	m_blackboard.Get("requireHelp", requireHelp);

	// can't answer own request for help, or help if already helping
	// or help if we need help
	// response is BIGNUMBER - distance to entity requiring help
	if (q->needsHelp != nullptr &&
		q->needsHelp != this &&
		m_blackboard.Contains("target") == false &&
		requireHelp == false) {

		float tx, ty;
		q->needsHelp->GetPosition(&tx, &ty);

		float xDiff = tx - m_position.x;
		float yDiff = ty - m_position.y;

		return 9999999.0f - (xDiff * xDiff + yDiff * yDiff);
	}
	return 0;
}

void BlackboardAgent::Execute(BlackboardQuestion* question, Blackboard* blackboard) {

	NeedHelpQuestion* q = (NeedHelpQuestion*)question;

	// changes state to helping questioner
	m_blackboard.Set("target", q->needsHelp);
}