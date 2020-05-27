#define _USE_MATH_DEFINES
#include <cmath>
#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "window.hpp"

Circle::Circle() :
    center_{ 0.0f, 0.0f },
    radius_{ 1.0f },
    color_{ 0.5f, 0.5f, 0.5f } {}

Circle::Circle(Vec2 const& ctr, float r) :
    center_{ ctr },
    radius_{ r } {}

Circle::Circle(Vec2 const& ctr, float r, Color const& clr) :
    center_{ ctr },
    radius_{ r },
    color_{ clr } {}

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

Vec2 Circle::ctr() const {
    return ctr_;
}

void Circle::draw(Window const& win) const {

    for (int i = 1; i <= 360; ++i) {
        Vec2 start((make_rotation_mat2(2 * M_PI * i / 360)) * Vec2 { radius(), 0 } +ctr());
        Vec2 end((make_rotation_mat2(2 * M_PI * (i + 1) / 360)) * Vec2 { radius(), 0 } +ctr());
        win.draw_line(start.x, start.y, end.x, end.y, color().r, color().g, color().b);
    }
}

void Circle::draw(Window const& win, Color const& color) const {

    for (int i = 1; i <= 360; ++i) {
        Vec2 start((make_rotation_mat2(2 * M_PI * i / 360)) * Vec2 { radius(), 0 } +ctr());
        Vec2 end((make_rotation_mat2(2 * M_PI * (i + 1) / 360)) * Vec2 { radius(), 0 } +ctr());
        win.draw_line(start.x, start.y, end.x, end.y, color.r, color.g, color.b);
    }
}

void Circle::draw(Window const& win, Color const& color, float thickness) const {

    for (int i = 1; i <= 360; ++i) {
        Vec2 start((make_rotation_mat2(2 * M_PI * i / 360)) * Vec2 { radius(), 0 } +ctr());
        Vec2 end((make_rotation_mat2(2 * M_PI * (i + 1) / 360)) * Vec2 { radius(), 0 } +ctr());
        win.draw_line(start.x, start.y, end.x, end.y, color.r, color.g, color.b, thickness);
    }
}

void Circle::draw(Window const& win, float thickness) const {

    for (int i = 1; i <= 360; ++i) {
        Vec2 start((make_rotation_mat2(2 * M_PI * i / 360)) * Vec2 { radius(), 0 } +ctr());
        Vec2 end((make_rotation_mat2(2 * M_PI * (i + 1) / 360)) * Vec2 { radius(), 0 } +ctr());
        win.draw_line(start.x, start.y, end.x, end.y, color().r, color().g, color().b, thickness);
    }
}

bool Circle::is_inside(Vec2 const& p) {
    float distance = sqrt(pow((ctr_.x - p.x), 2) + pow((ctr_.y - p.y), 2));
    if (distance <= radius_) {
        return true;
    }
    else { return false; }

}

