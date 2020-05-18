#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"


class Rectangle {

public:
    Rectangle(Vec2 const& min, Vec2 const& max);
    float area() const;
    float circumference() const;
    Vec2 max() const;
    Vec2 min() const;

private:
    Vec2 max_;
    Vec2 min_;
   

};

#endif // RECTANGLE_HPP