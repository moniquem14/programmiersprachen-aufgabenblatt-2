#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"

class Circle {
public:

    Circle(Vec2 const& ctr, float r, Color const& clr);

    Circle(Vec2 const& ctr, float r);

    float area() const;

    float circumference() const;

    Color color() const;

    Vec2 ctr() const;

    float radius() const;

    bool is_inside(Vec2 const& p);

    void draw(Window const& win) const;

    void draw(Window const& win, Color const& color) const;

    void draw(Window const& win, Color const& color, float thickness) const;

    void draw(Window const& win, float thickness) const;



private:
    Vec2 ctr_;
    float radius_ = 0;
    Color clr_;

};

#endif // CIRCLE_HPP