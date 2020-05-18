#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"

class Circle {
public:
    Circle(Vec2 const& ctr, float r);
    float area() const;
    float circumference() const;
    float radius() const;
    Vec2 center() const;
   

private:
    Vec2 center_;
    float radius_ = 0.0f;
    


};

#endif // CIRCLE_HPP