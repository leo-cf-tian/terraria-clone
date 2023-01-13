#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector2.hpp"

class PerlinNoise
{
public:
    // Compute Perlin noise at coordinates x, y
    static float perlin(Vector2 pos);

private:
    // Smoothstep Interpolation
    static float smoothstep(float x, float y, float w);

    // Random Gradient for Perlin Noise
    static Vector2 randomGradient(Vector2 vector);

    // Computes the dot product of the distance and gradient vectors.
    static float dotGridGradient(Vector2 ivec, Vector2 vec);
    
};
