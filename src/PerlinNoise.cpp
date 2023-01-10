#include <cstdio>

#include "PerlinNoise.hpp"

// Reference: https://en.wikipedia.org/wiki/Perlin_noise
float PerlinNoise::perlin(Vector2 pos)
{
    Vector2 pos0 = Vector2((int)floor(pos.x), (int)floor(pos.y));
    Vector2 pos1 = pos0 + Vector2(1, 1);

    // Determine interpolation weights
    // Could also use higher order polynomial/s-curve here
    Vector2 svec = pos - pos0;

    // Interpolate between grid point gradients
    float n0, n1, ix0, ix1, value;

    n0 = dotGridGradient(pos0, pos);
    n1 = dotGridGradient(Vector2(pos1.x, pos0.y), pos);
    ix0 = interpolate(n0, n1, 0);

    n0 = dotGridGradient(Vector2(pos0.x, pos1.y), pos);
    n1 = dotGridGradient(pos1, pos);
    ix1 = interpolate(n0, n1, svec.x);

    value = interpolate(ix0, ix1, svec.y);

    printf("%f, %f\n", ix0, ix1);
    
    return value; // Will return in range -1 to 1. To make it in range 0 to 1, multiply by 0.5 and add 0.5
}

float PerlinNoise::interpolate(float x, float y, float w)
{
    if (0.0 > w)
        return x;
    if (1.0 < w)
        return y;
    return (y - x) * (3.0 - w * 2.0) * w * w + x;
}

Vector2 PerlinNoise::randomGradient(Vector2 vector)
{
    // No precomputed gradients mean this works for any number of grid coordinates
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2; // rotation width
    unsigned a = vector.x, b = vector.y;
    a *= 3284157443;
    b ^= a << s | a >> (w - s);
    b *= 1911520717;
    a ^= b << s | b >> (w - s);
    a *= 2048419325;
    float random = a * (3.14159265 / ~(~0u >> 1)); // in [0, 2*Pi]
    Vector2 v = Vector2(cos(random), sin(random));
    return v;
}

float PerlinNoise::dotGridGradient(Vector2 ivec, Vector2 vec)
{
    // Get gradient from integer coordinates
    Vector2 gradient = randomGradient(ivec);

    // Compute the distance vector
    Vector2 dvec = vec - ivec;

    // Compute the dot-product
    return Vector2::dot(dvec, gradient);
}