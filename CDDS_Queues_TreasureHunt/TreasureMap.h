#pragma once

#include "Position.h"
#include <cstdlib>
#include <ctime>

// a TreasureMap is a square grid containing one treasure.
// The location of the treasure is not publicly known, but users can test a single position
// to see if it contains a treaure.
class TreasureMap {
public:
	TreasureMap(int mapSize) :
		m_mapSize(mapSize)
	{
		// seed the random number generator so it returns different 
		// results each time the program is run
		srand((unsigned int)time(nullptr));

		// put the treasure in a random position
		m_treasurePos.x = rand() % m_mapSize;
		m_treasurePos.y = rand() % m_mapSize;
	}

	// returns whether the treasure is at a given position
	bool isTreasurePos(const Position& guessPos) {
		return guessPos.x == m_treasurePos.x && guessPos.y == m_treasurePos.y;
	}

private:
	int m_mapSize;			// the size of each side of the map
	Position m_treasurePos;	// where the treaure is
};
