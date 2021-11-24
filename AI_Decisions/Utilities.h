#pragma once

// a collection of helpful functions
class Utilities
{
public:
	static int GetRouletteIndex(float* weights, int numWeights);
	static float Random(float min, float max);
};

