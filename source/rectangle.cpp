#include "rectangle.hpp"
#include <cmath>
#include "window.hpp"
#include "color.hpp"

Rectangle::Rectangle() :
    max_{ 600.0f, 400.0f },
    min_{ 400.0f, 200.0f },
    color_{ 0.7f, 0.7f, 0.7f },
    highlight_color_{ 0.1f,0.8f,0.7f } {}

Rectangle::Rectangle(Vec2 const& max, Vec2 const& min) :
    max_{ max },
    min_{ min } {}

Rectangle::Rectangle(Vec2 const& max, Vec2 const& min, Color const& rgb) :
    max_{ max },
    min_{ min },
    color_{ rgb } {}

float Rectangle::width() const {
    float er = min_.x - max_.x;
    if (er < 0) {
        return er * (-1);
    }
    else { return er; }
}

float Rectangle::height() const {
    float er = min_.y - max_.y;
    if (er < 0) {
        return er * (-1);
    }
    else { return er; }
}

float Rectangle::circumference() const {
    return 2 * (width() + height());
}

Color Rectangle::color() const {
    return color_;
}

Vec2 Rectangle::max() const {
    return max_;
}

Vec2 Rectangle::min() const {
    return min_;
}

void Rectangle::draw(Window const& win) const {
    win.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b);   // to the right
    win.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b);   // up
    win.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b);   // to the left
    win.draw_line(min_.x, max_.y, min_.x, min_.y, color_.r, color_.g, color_.b);   // down
}

void Rectangle::draw(Window const& win, Color rgb, float thickness, bool const& highlight_color) const {
    if (highlight_color == true) {
        rgb = highlight_color_;
    } win.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
    win.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);
    win.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
    win.draw_line(min_.x, max_.y, min_.x, min_.y, color_.r, color_.g, color_.b, thickness);
}

bool Rectangle::is_inside(Vec2 const& p) const {
    if (min_.x <= p.x && p.x <= max_.x && min_.y <= p.y && p.y <= max_.y) {
        return true;
    }
    else {
        if (min_.x >= p.x && p.x >= max_.x && max_.y >= p.y && p.y >= min_.y) {
            return true;
        }
        else { return false; }
    }


}