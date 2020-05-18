#include <cmath>
#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"

Circle::Circle(Vec2 const& ctr, float r) {
    center_ = ctr;
    radius_ = r;
}

// area: pi * r^2
float Circle::area() const {
    return M_PI * pow(radius_, 2);
}

// circumference: pi * radius * 2
float Circle::circumference() const {
    return M_PI * radius_ * 2;
}

float Circle::radius() const {
    return radius_;
}

Vec2 Circle::center() const {
    return center_;
}