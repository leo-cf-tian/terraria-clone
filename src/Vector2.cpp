#include <cmath>

#include "Vector2.hpp"

Vector2::Vector2()
    : x(0.0f), y(0.0f){};

Vector2::Vector2(float p_x, float p_y)
    : x(p_x), y(p_y){};

float Vector2::length()
{
    return sqrt(x * x + y * y);
};

float Vector2::dot(Vector2 left, Vector2 right)
{
    return left.x * right.x + left.y * right.y;
}

float Vector2::distance(Vector2 left, Vector2 right)
{
    Vector2 diff = left - right;
    return sqrt(diff.x * diff.x + diff.y * diff.y);
};

Vector2 Vector2::normalize(Vector2 value)
{
    return value * value.length();
}

Vector2 Vector2::operator+(Vector2 const &vector) const
{
    Vector2 result(x + vector.x, y + vector.y);
    return result;
};

Vector2 &Vector2::operator+=(Vector2 const &vector)
{
    x += vector.x;
    y += vector.y;
    return *this;
};

Vector2 Vector2::operator-(Vector2 const &vector) const
{
    Vector2 result(x - vector.x, y - vector.y);
    return result;
};

Vector2 &Vector2::operator-=(Vector2 const &vector)
{
    x -= vector.x;
    y -= vector.y;
    return *this;
};

Vector2 Vector2::operator*(float num) const
{
    Vector2 result(x * num, y * num);
    return result;
};

Vector2 operator*(float num, Vector2 const &vector)
{
    Vector2 result(vector.x * num, vector.y * num);
    return result;
};

Vector2 &Vector2::operator*=(float num)
{
    x *= num;
    y *= num;
    return *this;
};

Vector2 Vector2::operator/(float num) const
{
    Vector2 result(x / num, y / num);
    return result;
};

Vector2 &Vector2::operator/=(float num)
{
    x /= num;
    y /= num;
    return *this;
};

bool Vector2::operator==(Vector2 vector) const
{
    if (vector.x == x &&vector.y == y)
        return true;
        
    return false;
};