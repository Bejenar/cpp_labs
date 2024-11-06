#include "Vector2.hpp"

float& Vector2::operator[](int index) {
    return (index == 0) ? x : y;
}

const float& Vector2::operator[](int index) const {
    return (index == 0) ? x : y;
}

bool Vector2::operator==(const Vector2& other) const {
    return x == other.x && y == other.y;
}

Vector2& Vector2::operator*=(float a) {
    x *= a;
    y *= a;
    return *this;
}

Vector2& Vector2::operator/=(float a) {
    x /= a;
    y /= a;
    return *this;
}

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2 operator*(const Vector2& v, float a) {
    return Vector2{v.x * a, v.y * a};
}

Vector2 operator*(float a, const Vector2& v) {
    return v * a;
}

Vector2 operator/(const Vector2& v, float a) {
    return Vector2{v.x / a, v.y / a};
}

Vector2 operator+(const Vector2& v, const Vector2& w) {
    return Vector2{v.x + w.x, v.y + w.y};
}

Vector2 operator-(const Vector2& v, const Vector2& w) {
    return Vector2{v.x - w.x, v.y - w.y};
}

std::ostream& operator<<(std::ostream& os, const Vector2& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}