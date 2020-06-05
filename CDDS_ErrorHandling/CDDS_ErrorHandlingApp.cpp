#include "CDDS_ErrorHandlingApp.h"
#include "raylib.h"

CDDS_ErrorHandlingApp::CDDS_ErrorHandlingApp() {

}

CDDS_ErrorHandlingApp::~CDDS_ErrorHandlingApp() {

}

bool CDDS_ErrorHandlingApp::Startup() {

	Texture2D frame1 = LoadTexture("alienGreen_walk1.png");
	Texture2D frame2 = LoadTexture("alienGreen_walk2.png");

	m_sprite.AddFrame(frame1, 0.3f);
	m_sprite.AddFrame(frame2, 0.3f);

	m_position.x = GetScreenWidth() >> 1;
	m_position.y = GetScreenHeight() >> 1;

	return true;
}

void CDDS_ErrorHandlingApp::Shutdown() {
}

void CDDS_ErrorHandlingApp::Update(float deltaTime) {
	m_sprite.Update(deltaTime);
}

void CDDS_ErrorHandlingApp::Draw() {

	// wipe the screen to the background colour
	ClearBackground(RAYWHITE);

	// draw your stuff here!
	m_sprite.Draw(m_position.x, m_position.y, DRAW_FLIP_X | DRAW_FLIP_Y);

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 0, 0, 14, BLACK);
}