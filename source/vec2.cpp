#include "vec2.hpp"

// definition addition for Vec2
Vec2& Vec2::operator+=(Vec2 const& v) {
    x += v.x;
    y += v.y;
    return *this;
}

// definition multiplication for Vec2
Vec2& Vec2::operator*=(float s) {
    x *= s;
    y *= s;
    return *this;
}

// definition subtraction for Vec2
Vec2& Vec2::operator-=(Vec2 const& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

// definition division for Vec2
Vec2& Vec2::operator/=(float s) {
    x /= s;
    y /= s;
    return *this;
}

/*Free Functions */

Vec2 operator+(Vec2 const& u, Vec2 const& v) {
    return Vec2{ u.x + v.x, u.y + v.y };
}

Vec2 operator-(Vec2 const& u, Vec2 const& v) {
    return Vec2{ u.x - v.x, u.y - v.y };
}

Vec2 operator*(Vec2 const& v, float s) {
    return Vec2{ v.x * s, v.y * s };
}

Vec2 operator/(Vec2 const& v, float s) {
    if (s == 0) {
        return v;
    } return Vec2{ v.x / s, v.y / s };
}

Vec2 operator*(float s, Vec2 const& v) {
    return v * s;
}