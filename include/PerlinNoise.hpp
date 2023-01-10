#pragma once
#include "Vector2.hpp"

class PerlinNoise
{
public:
    // Compute Perlin noise at coordinates x, y
    static float perlin(Vector2 pos);

private:
    // Linear Interpolation
    static float interpolate(float x, float y, float w);

    // Random Gradient for Perlin Noise
    static Vector2 randomGradient(Vector2 vector);

    // Computes the dot product of the distance and gradient vectors.
    static float dotGridGradient(Vector2 ivec, Vector2 vec);
};
