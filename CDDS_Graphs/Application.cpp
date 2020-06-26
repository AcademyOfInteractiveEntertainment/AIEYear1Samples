#include "Application.h"
#include "raylib.h"
#include "Graph.h"

Application::Application(int screenWidth, int screenHeight) : m_screenWidth(screenWidth), m_screenHeight(screenHeight) {
}

Application::~Application() {

	delete m_pGraph;
}

bool Application::Startup() {

	InitWindow(m_screenWidth, m_screenHeight, "Application");
	SetTargetFPS(60);


	m_pGraph = new Graph();

	Graph::Node* a = m_pGraph->AddNode(Vector2{ 100, 100 });
	Graph::Node* b = m_pGraph->AddNode(Vector2{ 150, 100 });
	Graph::Node* c = m_pGraph->AddNode(Vector2{ 200, 100 });
	Graph::Node* d = m_pGraph->AddNode(Vector2{ 150, 150 });
	Graph::Node* e = m_pGraph->AddNode(Vector2{ 100, 200 });
	Graph::Node* f = m_pGraph->AddNode(Vector2{ 150, 200 });
	Graph::Node* g = m_pGraph->AddNode(Vector2{ 200, 200 });
	Graph::Node* h = m_pGraph->AddNode(Vector2{ 300, 150 });
	Graph::Node* i = m_pGraph->AddNode(Vector2{ 250, 100 });
	Graph::Node* j = m_pGraph->AddNode(Vector2{ 300, 100 });
	Graph::Node* k = m_pGraph->AddNode(Vector2{ 350, 100 });

	m_pGraph->ConnectNodes(a, d, 1);
	m_pGraph->ConnectNodes(b, d, 1);
	m_pGraph->ConnectNodes(c, d, 1);
	m_pGraph->ConnectNodes(d, h, 1);
	m_pGraph->ConnectNodes(d, e, 1);
	m_pGraph->ConnectNodes(d, f, 1);
	m_pGraph->ConnectNodes(d, g, 1);
	m_pGraph->ConnectNodes(i, h, 1);
	m_pGraph->ConnectNodes(j, h, 1);
	m_pGraph->ConnectNodes(k, h, 1);

	return true;
}

void Application::Shutdown() {

	CloseWindow();        // Close window and OpenGL context
}

void Application::Update(float deltaTime) {
	
	if (IsMouseButtonPressed(0))
	{	
		Vector2 position = GetMousePosition();
		Graph::Node* newNode = m_pGraph->AddNode(position);

		// find all nodes within 50 px of this one
		std::list<Graph::Node*>list;
		m_pGraph->FindNodes(list, position, 50.0f);
		for (std::list<Graph::Node*>::iterator it = list.begin(); it != list.end(); it++)
		{
			if (newNode != *it) {
				m_pGraph->ConnectNodes(newNode, *it);
			}
		}
	}
}

void Application::Draw() {
	BeginDrawing();

	ClearBackground(BLACK);

	m_pGraph->Draw();

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}