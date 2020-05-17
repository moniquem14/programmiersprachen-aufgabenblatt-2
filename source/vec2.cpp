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