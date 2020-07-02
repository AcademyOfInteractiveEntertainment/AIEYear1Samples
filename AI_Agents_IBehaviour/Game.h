
/*-----------------------------------------------------------------------------
Author:			Elizabeth Rowlands			
Description:	Steering Behaviors 1
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "raylib.h"

class Agent;
class KeyboardBehavior;

class Game
{
public:
	// assets loaded in constructor
	Game(unsigned int windowWidth, unsigned int windowHeight, const char *title);

	// assets destroyed in destructor
	virtual ~Game();

	bool Startup();
	void Shutdown();

	// update / draw called each frame automaticly
	virtual void Update(float deltaTime);
	virtual void Draw();
		
private:	
	Agent *m_testAgent;
	KeyboardBehavior *m_keyboardBehavior;

	Texture2D m_agentTexture;
	Texture2D m_mouseTexture;
};

#endif