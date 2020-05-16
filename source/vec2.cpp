#include "vec2.hpp"

//default constructor
Vec2::Vec2() :
    x{ 0.0f },
    y{ 0.0f } {}

// var constructor
Vec2::Vec2(float x, float y) :
    x{ x },
    y{ y } {}

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