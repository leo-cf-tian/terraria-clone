#pragma once
#include <cmath>

struct Vector2
{
    float x, y;
    Vector2();
    Vector2(float x, float y);
    float length();
    static float dot(Vector2 left, Vector2 right);
    static float distance(Vector2 left, Vector2 right);
    static Vector2 normalize(Vector2 value);

    Vector2 operator+(Vector2 const &vector) const;
    Vector2 &operator+=(Vector2 const &vector);
    Vector2 operator-(Vector2 const &vector) const;
    Vector2 &operator-=(Vector2 const &vector);
    Vector2 operator*(float num) const;
    Vector2 &operator*=(float num);
    Vector2 operator/(float num) const;
    Vector2 &operator/=(float num);
    bool operator==(Vector2 vector) const;
};