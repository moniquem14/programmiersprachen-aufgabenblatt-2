#include "rectangle.hpp"
#include <cmath>
#include "window.hpp"
#include "color.hpp"

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& clr) {
    max_ = max;
    min_ = min;
    clr_ = clr;
}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max) {
    if(min.x <= max.x && min.y >= max.y){
    max_ = max;
    min_ = min;
    }
    else{
    max_ = min;
    min_ = max;
    }
}

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

Color Rectangle::color() const {
    return clr_;
}

float Rectangle::area() const {
    return height() * width();
}

float Rectangle::circumference() const {
    return 2 * (width() + height());
}

Vec2 Rectangle::max() const {
    return max_;
}

Vec2 Rectangle::min() const {
    return min_;
}

void Rectangle::draw(Window const& win) const {
    win.draw_line(min().x, min().y, min().x, max().y, color().r, color().g, color().b);
    win.draw_line(min().x, min().y, max().x, min().y, color().r, color().g, color().b);
    win.draw_line(max().x, min().y, max().x, max().y, color().r, color().g, color().b);
    win.draw_line(max().x, max().y, min().x, max().y, color().r, color().g, color().b);
}

void Rectangle::draw(Window const& win, Color color) const {
    win.draw_line(min().x, min().y, min().x, max().y, color.r, color.g, color.b);
    win.draw_line(min().x, min().y, max().x, min().y, color.r, color.g, color.b);
    win.draw_line(max().x, min().y, max().x, max().y, color.r, color.g, color.b);
    win.draw_line(max().x, max().y, min().x, max().y, color.r, color.g, color.b);
}

void Rectangle::draw(Window const& win, Color color, float thickness) const {
    win.draw_line(min().x, min().y, min().x, max().y, color.r, color.g, color.b, thickness);
    win.draw_line(min().x, min().y, max().x, min().y, color.r, color.g, color.b, thickness);
    win.draw_line(max().x, min().y, max().x, max().y, color.r, color.g, color.b, thickness);
    win.draw_line(max().x, max().y, min().x, max().y, color.r, color.g, color.b, thickness);
}

void Rectangle::draw(Window const& win, float thickness) const {
    win.draw_line(min().x, min().y, min().x, max().y, color().r, color().g, color().b, thickness);
    win.draw_line(min().x, min().y, max().x, min().y, color().r, color().g, color().b, thickness);
    win.draw_line(max().x, min().y, max().x, max().y, color().r, color().g, color().b, thickness);
    win.draw_line(max().x, max().y, min().x, max().y, color().r, color().g, color().b, thickness);
}