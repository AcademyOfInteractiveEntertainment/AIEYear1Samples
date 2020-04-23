#include "BlackboardState.h"


void HelpEntityState::Update(Agent* agent, float deltaTime) {

	Agent* target = nullptr;
	agent->GetBlackboard().Get("target", &target);

	if (target == nullptr)
		return;

	float speed = 0;
	agent->GetBlackboard().Get("speed", speed);

	// move to target
	// get target position
	float tx = 0, ty = 0;
	target->GetPosition(&tx, &ty);

	// get my position
	float x = 0, y = 0;
	agent->GetPosition(&x, &y);

	// compare the two and get the distance between them
	float xDiff = tx - x;
	float yDiff = ty - y;
	float distance = xDiff * xDiff + yDiff * yDiff;

	// if not at the target then move towards them
	if (distance > 25) {

		distance = sqrt(distance);
		xDiff /= distance;
		yDiff /= distance;

		// move to target
		agent->Translate(xDiff * speed * deltaTime, yDiff * speed * deltaTime);
	}
	else {
		// tag, they're helped!
		target->GetBlackboard().Set("requireHelp", false);
		agent->GetBlackboard().Remove("target");
	}
}