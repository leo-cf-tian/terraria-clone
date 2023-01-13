#include <cstdio>

#include "PerlinNoise.hpp"

// Code is based on perlin noise implementation from: https://en.wikipedia.org/wiki/Perlin_noise
float PerlinNoise::perlin(Vector2 pos)
{
    Vector2 start = Vector2(floor(pos.x), floor(pos.y));
    Vector2 end = start + Vector2(1, 1);

    Vector2 relPos = pos - start;

    float left, right, topline, bottomline, value;

    left = dotGridGradient(start, pos);
    right = dotGridGradient(Vector2(end.x, start.y), pos);
    topline = smoothstep(left, right, relPos.x);

    left = dotGridGradient(Vector2(start.x, end.y), pos);
    right = dotGridGradient(end, pos);
    bottomline = smoothstep(left, right, relPos.x);

    value = smoothstep(topline, bottomline, relPos.y);
    return value;
}

float PerlinNoise::smoothstep(float edge1, float edge2, float x)
{
    if (x < 0)
        return edge1;
    if (x > 1)
        return edge2;
    return (3.0 - x * 2.0) * x * x * (edge2 - edge1) + edge1;
}

Vector2 PerlinNoise::randomGradient(Vector2 vector)
{
    // random number mapping from https://en.wikipedia.org/wiki/Perlin_noise
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

float PerlinNoise::dotGridGradient(Vector2 vertex, Vector2 pos)
{
    Vector2 gradient = randomGradient(vertex);
    Vector2 dist = pos - vertex;

    return Vector2::dot(gradient, dist);
}