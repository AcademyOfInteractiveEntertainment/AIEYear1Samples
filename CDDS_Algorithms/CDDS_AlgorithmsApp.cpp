#include "CDDS_AlgorithmsApp.h"

CDDS_AlgorithmsApp::CDDS_AlgorithmsApp() : m_isGameOver(false), m_currentPlayer(1) {

}

CDDS_AlgorithmsApp::~CDDS_AlgorithmsApp() {

}

bool CDDS_AlgorithmsApp::startup() {

	m_croissant = LoadTexture("croissant.png");
	m_cupcake = LoadTexture("cake.png");

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			m_board[i][j] = 0;
		}
	}

	return true;
}

void CDDS_AlgorithmsApp::shutdown() 
{
	UnloadTexture(m_croissant);
	UnloadTexture(m_cupcake);
}

// As an activity, optimize this algorithm
// You can use the web to see if any innovative solutions exist (there are some very clever approaches)
// At a minimum, you should be able to recognise that half of the checks in this function are
// redundant - because we step through the game board left-to-right, the checks that search for matches
// from right-to-left are unneeded.
// A better approach is to store all 69 (or so?) win conditions in a table and access them by using the 
// last place tile as an index. (thats kind of a lot of work though)
bool CDDS_AlgorithmsApp::checkForWin()
{
	// brute force approach -- is there a better way? (hint: yes, there is)

	for (int x = 0; x < COLUMNS; x++)
	{
		for (int y = 0; y < ROWS; y++)
		{
			int tile = m_board[x][y];
			if (tile == 0)
				continue;
			// check right horizontal
			if (x + 3 < COLUMNS && tile == m_board[x + 1][y] && tile == m_board[x + 2][y] && tile == m_board[x + 3][y])
				return true;
			// check left horizontal
			if (x - 3 >= 0 && tile == m_board[x - 1][y] && tile == m_board[x - 2][y] && tile == m_board[x - 3][y])
				return true;
			// check up
			if (y + 3 < ROWS && tile == m_board[x][y + 1] && tile == m_board[x][y + 2] && tile == m_board[x][y + 3])
				return true;
			// check down
			if (y - 3 >= 0 && tile == m_board[x][y - 1] && tile == m_board[x][y - 2] && tile == m_board[x][y - 3])
				return true;
			// diagonal down and right
			if (x + 3 < COLUMNS && y - 3 >= 0 && tile == m_board[x + 1][y - 1] && tile == m_board[x + 2][y - 2] && tile == m_board[x + 3][y - 3])
				return true;
			// diagonal down and left
			if (x - 3 >= 0 && y - 3 >= 0 && tile == m_board[x - 1][y - 1] && tile == m_board[x - 2][y - 2] && tile == m_board[x - 3][y - 3])
				return true;
			// diagonal up and right
			if (x + 3 < COLUMNS && y + 3 < ROWS && tile == m_board[x + 1][y + 1] && tile == m_board[x + 2][y + 2] && tile == m_board[x + 3][y + 3])
				return true;
			// diagonal up and left
			if (x - 3 >= 0 && y + 3 >= ROWS && tile == m_board[x - 1][y + 1] && tile == m_board[x - 2][y + 2] && tile == m_board[x - 3][y + 3])
				return true;
		}
	}
	return false;
}

void CDDS_AlgorithmsApp::update(float deltaTime) {
	static int height = GetScreenHeight();
	static int width = GetScreenWidth();
	static bool wasMouseDown = false;


	if (!m_isGameOver) {
		if (IsMouseButtonDown(0) && wasMouseDown == false)
		{
			Vector2 position = GetMousePosition();

			float xInc = (width - (BORDER << 1)) / COLUMNS;
			int col = (position.x - BORDER) / xInc;

			if (col >= 0 && col < COLUMNS) {
				// find the lowest row and place a tile there
				for (int row = 0; row < ROWS; row++)
				{
					if (m_board[col][row] == 0) {
						m_board[col][row] = m_currentPlayer;

						m_currentPlayer = (m_currentPlayer == 1) ? 2 : 1;

						break;
					}
				}
			}
		}
		wasMouseDown = IsMouseButtonDown(0);

		m_isGameOver = checkForWin();
	}
}

void CDDS_AlgorithmsApp::draw() {
	static int height = GetScreenHeight();
	static int width = GetScreenWidth();

	// wipe the screen to the background colour
	ClearBackground(RAYWHITE);

	// draw game board
	float xInc = (width - (BORDER << 1)) / COLUMNS;
	float yInc = (height - (BORDER << 1)) / ROWS;
	for (int x = 0; x <= COLUMNS; x++) {
		DrawLine(BORDER + x * xInc, BORDER + yInc * ROWS, BORDER + x * xInc, BORDER, BLACK);
	}
	for (int y = 0; y <= ROWS; y++) {
		DrawLine(BORDER, BORDER + y * yInc, BORDER + xInc * COLUMNS, BORDER + y * yInc, BLACK);
	}

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			if (m_board[i][j] == 1) {
				DrawTextureEx(m_croissant, Vector2{ BORDER + i * xInc, height - BORDER - (j + 1) * yInc }, 0, 0.5f, WHITE);
			}
			else if (m_board[i][j] == 2) {
				DrawTextureEx(m_cupcake, Vector2{ BORDER + i * xInc, height - BORDER - (j + 1) * yInc }, 0, 0.4f, WHITE);
			}
		}
	}

	if (m_isGameOver) {
		DrawText("GAME OVER", (width >> 1) - 50, height - 30, 20, BLACK);
	}
	else {
		if (m_currentPlayer == 1) {
			DrawText("Player 1 go", 10, height - 30, 14, BLACK);
		}
		else {
			DrawText("Player 2 go", 10, height - 30, 14, BLACK);
		}
	}
		
	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 0, 0, 14, BLACK);
}