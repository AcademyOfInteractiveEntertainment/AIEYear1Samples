#include "SteeringBehaviour.h"
#include "Blackboard.h"


eBehaviourResult SteeringBehaviour::Execute(Agent* agent, float deltaTime) {

	Force force = { 0,0 };

	Vector2* velocity = nullptr;
	// must have velocity
	if (agent->GetBlackboard().Get("velocity", &velocity) == false)
		return eBehaviourResult::FAILURE;

	for (auto& wf : m_forces) {
		Force temp = wf.force->GetForce(agent);

		// accumulate forces
		force.x += temp.x * wf.weight;
		force.y += temp.y * wf.weight;
	}

	float maxVelocity = 0;
	agent->GetBlackboard().Get("maxVelocity", maxVelocity);

	velocity->x += force.x * deltaTime;
	velocity->y += force.y * deltaTime;

	// cap velocity
	float magnitudeSqr = velocity->x * velocity->x + velocity->y * velocity->y;
	if (magnitudeSqr > (maxVelocity * maxVelocity)) {
		float magnitude = sqrt(magnitudeSqr);
		velocity->x = velocity->x / magnitude * maxVelocity;
		velocity->y = velocity->y / magnitude * maxVelocity;
	}

	agent->Translate(velocity->x * deltaTime, velocity->y * deltaTime);

	return eBehaviourResult::SUCCESS;
}

void SteeringState::Update(Agent* agent, float deltaTime) {

	Force force = { 0,0 };

	for (auto& wf : m_forces) {
		Force temp = wf.force->GetForce(agent);

		// accumulate forces
		force.x += temp.x * wf.weight;
		force.y += temp.y * wf.weight;
	}

	float maxVelocity = 0;
	agent->GetBlackboard().Get("maxVelocity", maxVelocity);

	Vector2* velocity = nullptr;
	agent->GetBlackboard().Get("velocity", &velocity);

	velocity->x += force.x * deltaTime;
	velocity->y += force.y * deltaTime;

	// cap velocity
	float magnitudeSqr = velocity->x * velocity->x + velocity->y * velocity->y;
	if (magnitudeSqr > (maxVelocity * maxVelocity)) {
		float magnitude = sqrt(magnitudeSqr);
		velocity->x = velocity->x / magnitude * maxVelocity;
		velocity->y = velocity->y / magnitude * maxVelocity;
	}

	agent->Translate(velocity->x * deltaTime, velocity->y * deltaTime);
}

Vector2 WanderForce::SetAngle(Vector2 vector, float value) const
{
	float length = Vector2Length(vector);
	return { cosf(value) * length, sinf(value) * length };
}

Force WanderForce::GetForce(Agent* agent) const {

	WanderData* wd = nullptr;
	if (agent->GetBlackboard().Get("wanderData", &wd) == false) {
		return{ 0,0 };
	}

	Vector2* velocity = nullptr;
	agent->GetBlackboard().Get("velocity", &velocity);

	if (Vector2Length(*velocity) == 0)
	{
		*velocity = { 0, -1 };
	}

	// The code to calculate the circle center:
	// m_circleDistance from the current agent position, in the same direction as the current velocity
	Vector2 circleCenter = Vector2Scale(Vector2Normalize(*velocity), wd->circleDistance);

	Vector2 displacement = { 0, -1 };
	displacement = Vector2Scale(displacement, wd->circleRadius);
	//
	// Randomly change the vector direction
	// by making it change its current angle
	displacement = SetAngle(displacement, wd->wanderAngle);

	//
	// Change wanderAngle just a bit, so it
	// won't have the same value in the
	// next game frame.	
	wd->wanderAngle += (rand() % (int)wd->angleChange) - wd->angleChange* .5;

	Vector2 wanderForce = Vector2Add(circleCenter, displacement);


	float maxForce = 0;
	agent->GetBlackboard().Get("maxForce", maxForce);

	return{ wanderForce.x * maxForce, wanderForce.y * maxForce }; 

	/*

	// generate a random circular direction with a radius of "jitter"
	//glm::vec2 jitterOffset = glm::circularRand(wd->jitter);

	float wanderX = wd->x, wanderY = wd->y;

	// apply the jitter to our current wander target
	wanderX += wd->jitter;//jitterOffset.x;
	wanderY += 0;//jitterOffset.y;

	// bring it back to a radius around the game object
	float magnitude = sqrt(wanderX * wanderX + wanderY * wanderY);
	wanderX = (wanderX / magnitude) * wd->radius;
	wanderY = (wanderY / magnitude) * wd->radius;

	// store the target back into the game object
	wd->x = wanderX;
	wd->y = wanderY;

	// access the game object's velocity as a unit vector (normalised)
	Vector2* velocity = nullptr;
	agent->GetBlackboard().Get("velocity", &velocity);
	float vx = velocity->x;
	float vy = velocity->y;

	// normalise and protect from divide-by-zero
	magnitude = vx * vx + vy * vy;
	if (magnitude > 0) {
		magnitude = sqrt(magnitude);
		vx /= magnitude;
		vy /= magnitude;
	}
	
	// combine velocity direction with wander target to offset
	wanderX += vx * wd->offset;
	wanderY += vy * wd->offset;

	// normalise the new direction
	magnitude = wanderX * wanderX + wanderY * wanderY;
	if (magnitude > 0) {

		magnitude = sqrt(magnitude);
		wanderX /= magnitude;
		wanderY /= magnitude;
	}

	float maxForce = 0;
	agent->GetBlackboard().Get("maxForce", maxForce);

	return{ wanderX * maxForce, wanderY * maxForce };*/
}
