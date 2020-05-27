#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"

class Circle {
public:

    Circle(Vec2 const& ctr, float r, Color const& rgb);

    Circle(Vec2 const& ctr, float r);

    float area() const;

    float circumference() const;

    Color color() const;

    Vec2 center() const;

    float radius() const;

    bool is_inside(Vec2 const& p);

    void draw(Window const& win) const;

    void draw(Window const& win, Color clr, float thickness, bool const& highlight_color) const;



private:
    Vec2 ctr_;
    float radius_ = 0;
    Color clr_;
    Color highlight_color_;
};

#endif // CIRCLE_HPP