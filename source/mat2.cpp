#include "mat2.hpp"
#include <cmath>
#include <iostream>

// definition of operator*= for mat2
Mat2& Mat2::operator*=(Mat2 const& m) {
    float m_1 = e_00 * m.e_00 + e_01 * m.e_10;
    float m_2 = e_00 * m.e_01 + e_01 * m.e_11;
    float m_3 = e_10 * m.e_00 + e_11 * m.e_10;
    float m_4 = e_10 * m.e_01 + e_11 * m.e_11;

    // return Mat2{m_1, m_2, m_3, m_4};
    e_00 = m_1;
    e_01 = m_2;
    e_10 = m_3;
    e_11 = m_4;
    return *this;
}

// defintion determinant 
float Mat2::det() const {
    return e_00 * e_11 - e_10 * e_01;
}

/*--- Free Functions of mat2 -------------------------*/

// definition of operator* for mat2
Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
    return Mat2{ (m1.e_00 * m2.e_00 + m1.e_01 * m2.e_10),
                (m1.e_00 * m2.e_01 + m1.e_01 * m2.e_11),
                (m1.e_10 * m2.e_00 + m1.e_11 * m2.e_10),
                (m1.e_10 * m2.e_01 + m1.e_11 * m2.e_11) };
}

// Matrix * Vector
Vec2 operator*(Mat2 const& m, Vec2 const& v) {
    return Vec2{ (m.e_00 * v.x + m.e_01 * v.y),
                (m.e_10 * v.x + m.e_11 * v.y) };
}

// Vector * Matrix
Vec2 operator*(Vec2 const& v, Mat2 const& m) {
    return Vec2{ (m.e_00 * v.x + m.e_01 * v.y),
                (m.e_10 * v.x + m.e_11 * v.y) };
}

// Inverse Matrix
Mat2 inverse(Mat2 const& m) {
    return Mat2{ (m.e_11, -m.e_01, -m.e_10, m.e_10) /
                (m.e_00 * m.e_11 - m.e_01 * m.e_10) };
}

// Transpose Matrix
Mat2 transpose(Mat2 const& m) {
    return Mat2{ m.e_00, m.e_10, m.e_01, m.e_11 };
}

// Rotate Matrix
Mat2 make_rotation_mat2(float phi) {
    return Mat2{ std::cos(phi), (-1) * std::sin(phi), std::sin(phi), std::cos(phi) };
}


