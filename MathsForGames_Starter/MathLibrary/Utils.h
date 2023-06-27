#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

namespace aie
{
	const float MAX_FLOAT_DELTA = 0.00001f;

	inline float ApproximatelyEquals(float a, float b)
	{
		
	}

    inline float AngleFrom2D(float x, float y)
    {
        
    }

    const float Pi = 3.14159265358979323846264338327950288f;

    // Deg2Rad
    const float Deg2Rad = Pi * 2.0f / 360.0f;

    // Rad2Deg
    const float Rad2Deg = 1.0f / Deg2Rad;
}