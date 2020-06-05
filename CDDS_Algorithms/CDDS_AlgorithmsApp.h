#pragma once


#include "raylib.h"

const int COLUMNS = 7;
const int ROWS = 6;
const int BORDER = 50;


class CDDS_AlgorithmsApp {
public:

	CDDS_AlgorithmsApp();
	~CDDS_AlgorithmsApp();

	bool startup();
	void shutdown();

	void update(float deltaTime);
	void draw();

	bool checkForWin();

protected:
		
	int	m_board[COLUMNS][ROWS];
	int	m_currentPlayer;
	bool m_isGameOver;	

	Texture2D m_croissant;
	Texture2D m_cupcake;
};