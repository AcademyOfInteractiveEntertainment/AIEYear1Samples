#include "CDDS_QuadTreeApp.h"
#include "GameObject.h"
#include <random>
#include <time.h>
#include "raylib.h"

CDDS_QuadTreeApp::CDDS_QuadTreeApp() {

}

CDDS_QuadTreeApp::~CDDS_QuadTreeApp() {

}

bool CDDS_QuadTreeApp::Startup() {

	m_rock = LoadTexture("rock_small.png");

	srand(time(nullptr));
	for (int i = 0; i < 50; i++)
	{
		m_quadtree.Insert(new GameObject(&m_rock, Vector2{ (float)(rand() % 1280), (float)(rand() % 740) }));
	}

	return true;
}

void CDDS_QuadTreeApp::Shutdown() {
	UnloadTexture(m_rock);
}

void CDDS_QuadTreeApp::Update(float deltaTime) {

}

void CDDS_QuadTreeApp::Draw() {

	// wipe the screen to the background colour
	ClearBackground(RAYWHITE);

	// draw your stuff here!
	m_quadtree.Draw();

	// output some text
	DrawText("Press ESC to quit", 0, 0, 14, BLACK);
}