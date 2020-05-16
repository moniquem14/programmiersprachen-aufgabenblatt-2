#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"
#include <array>

// mat2 definition
struct Mat2 {

    // matrix layout:
    //   e_00   e_10
    //   e_01   e_11

    // default constructor
    Mat2();

    Mat2(float e1, float e2, float e3, float e4);

    // member variables
    float e_00 = 1.0f;
    float e_10 = 0.0f;
    float e_01 = 0.0f;
    float e_11 = 1.0f;

    // operator *=
    Mat2& operator *=(Mat2 const& m);

    // determinant
    float det() const;

};

// free functions
Mat2 operator*(Mat2 const& m1, Mat2 const& m2);   // M x M
Vec2 operator*(Mat2 const& m, Vec2 const& v);     // M x V
Vec2 operator*(Vec2 const& v, Mat2 const& m);     // V x M
Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);


#endif //MAT2_HPP