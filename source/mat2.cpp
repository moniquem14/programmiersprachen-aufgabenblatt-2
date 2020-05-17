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
    float m_1 = e_00 * m.e_00 + e_01 * m.e_10;
    float m_2 = e_00 * m.e_01 + e_01 * m.e_11;
    float m_3 = e_10 * m.e_00 + e_11 * m.e_10;
    float m_4 = e_10 * m.e_01 + e_11 * m.e_11;
    e_00 = m_1;
    e_01 = m_2;
    e_10 = m_3;
    e_11 = m_4;
    return *this;
}

// defintion determinate 
float Mat2::det() const {
    return e_00 * e_11 - e_10 * e_01;
}


/* ------------------------------
 *  F R E E  F U N C T I O N S
 * -----------------------------*/

 // definition of operator* for mat2
Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
    return Mat2{ (m1.e_00 * m2.e_00 + m1.e_01 * m2.e_10),
                (m1.e_00 * m2.e_01 + m1.e_01 * m2.e_11),
                (m1.e_10 * m2.e_00 + m1.e_11 * m2.e_10),
                (m1.e_10 * m2.e_01 + m1.e_11 * m2.e_11) };
}

// Matrix * Vector
Vec2 operator*(Mat2 const& m, Vec2 const& v) {

}

// Vector * Matrix
Vec2 operator*(Vec2 const& v, Mat2 const& m) {

}

// Inverse Matrix
Mat2 inverse(Mat2 const& m) {

}

// Transpose Matrix
Mat2 transpose(Mat2 const& m) {

}

// Rotate Matrix
Mat2 make_rotation_mat2(float phi) {

}

