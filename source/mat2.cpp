#include "mat2.hpp"

Mat2::Mat2() :
    e_00{ 1.0f },
    e_01{ 0.0f },
    e_10{ 0.0f },
    e_11{ 1.0f } {}

Mat2::Mat2(float e1, float e2, float e3, float e4) :
    e_00{ e1 },
    e_01{ e2 },
    e_10{ e3 },
    e_11{ e4 } {}

// definition of operator*= for mat2
Mat2& Mat2::operator*=(Mat2 const& m) {

}

// definition of operator* for mat2
Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {

}