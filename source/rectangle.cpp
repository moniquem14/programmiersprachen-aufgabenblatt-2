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
    //if(min.x <= max.x && min.y >= max.y){
    max_ = max;
    min_ = min;
    //} else{
    max_ = min;
    min_ = max;
    //}
}

