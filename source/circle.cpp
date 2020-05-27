#define _USE_MATH_DEFINES
#include "circle.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <cmath>

Circle::Circle() :
    center_{ 0.0f, 0.0f },
    radius_{ 1.0f },
    color_{ 0.5f, 0.5f, 0.5f },
    highlight_color_{ 0.1f,0.8f,0.7f } {}

Circle::Circle(Vec2 const& ctr, float r) :
    center_{ ctr },
    radius_{ r } {}

Circle::Circle(Vec2 const& ctr, float r, Color const& rgb) :
    center_{ ctr },
    radius_{ r },
    color_{ rgb } {}


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

void Circle::draw(Window const& win) const {
    for (int i = 0; i <= 500; ++i) {
        Vec2 start = make_rotation_mat2((2 * M_PI) / 500 * i) * Vec2 { radius_, 0 } +center_;
        Vec2 end = make_rotation_mat2((2 * M_PI) / 500 * (i + 1)) * Vec2 { radius_, 0 } +center_;
        win.draw_line(start.x, start.y, end.x, end.y, color_.r, color_.g, color_.b);
    }
}

void Circle::draw(Window const& win, Color rgb, float thickness, bool const& highlight_color) const {
    if (highlight_color == true) {
        rgb = highlight_color_;
    } 
    for (int i = 0; i <= 500; ++i) {
        Vec2 start = make_rotation_mat2((2 * M_PI) / 500 * i) * Vec2 { radius_, 0 } +center_;
        Vec2 end = make_rotation_mat2((2 * M_PI) / 500 * (i + 1)) * Vec2 { radius_, 0 } +center_;
        win.draw_line(start.x, start.y, end.x, end.y, color_.r, color_.g, color_.b, thickness);
    }
}

bool Circle::is_inside(Vec2 const& p) {
    float distance = sqrt(pow((center_.x - p.x), 2) + pow((center_.y - p.y), 2));
    if (distance <= radius_) {
        return false;
    }
    return false;

}