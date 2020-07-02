#ifndef IBEHAVIOR_H
#define IBEHAVIOR_H

//--------
//	Breif: Interface class for all behaviors to inherit from
//	Author: Elizabeth Rowlands
//	Date : 4/3/2015
//--------
class MovementInfo;

class IBehavior
{
public:
	IBehavior(){};
	virtual ~IBehavior() = 0 {};
	virtual void Update(float deltaTime, MovementInfo& behaviour) = 0;
};

#endif

