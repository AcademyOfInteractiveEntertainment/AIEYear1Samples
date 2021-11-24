#include <random>
#include "Utilities.h"

int Utilities::GetRouletteIndex(float* weights, int numWeights)
{
    // sum all the weights in the array
    float total = 0;
    for (int i = 0; i < numWeights; i++)
    {
        total += weights[i];
    }

    // roll a dice in that range
    float dice = Random(0, total);

    // step throught he array accumulating values as we go
    // once it's exceeded the dice value return that index
    float accumulator = 0;
    for (int i = 0; i < total; i++)
    {
        accumulator += weights[i];
        if (accumulator >= dice)
            return i;
    }

    // edge case - if we rolled the absolute maximum, return the last value
    return numWeights-1;
}

float Utilities::Random(float min, float max)
{
    return min + (max - min) * (float)rand() / (float)RAND_MAX;
}
