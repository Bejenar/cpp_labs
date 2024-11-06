#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

struct Vector2 {
    float x, y;

    float& operator[](int index);
    const float& operator[](int index) const;

    bool operator==(const Vector2& other) const;
    Vector2& operator*=(float a);
    Vector2& operator/=(float a);
    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
};

Vector2 operator*(const Vector2& v, float a);
Vector2 operator*(float a, const Vector2& v);
Vector2 operator/(const Vector2& v, float a);
Vector2 operator+(const Vector2& v, const Vector2& w);
Vector2 operator-(const Vector2& v, const Vector2& w);
std::ostream& operator<<(std::ostream& os, const Vector2& v);

#endif // VECTOR2_H