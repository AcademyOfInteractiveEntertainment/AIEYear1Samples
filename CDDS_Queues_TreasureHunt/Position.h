#pragma once

// A simple struct to store a cartesian grid position
struct Position {
	// default the position to (0,0)
	Position() : x(0), y(0) {}

	int x;
	int y;
};
