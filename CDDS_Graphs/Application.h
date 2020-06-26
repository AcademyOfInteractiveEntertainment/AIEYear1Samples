#pragma once

class Graph;

class Application
{
public:

	// assets loaded in constructor
	Application(int screenWidth = 800, int screenHeight = 450);

	// assets destroyed in destructor
	~Application();

	bool Startup();
	void Shutdown();

	// update / draw called each frame automaticly
	void Update(float deltaTime);
	void Draw();

protected:
	int m_screenWidth;
	int m_screenHeight;


	Graph* m_pGraph;
};

