#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "vec2.hpp"
#include "mat2.hpp"
//#include "circle.hpp"
//#include "rectangle.hpp"
//#include "color.hpp"


/*
     MATRICES
*/

// testing initialization of instances
TEST_CASE("describe_mat2", "[mat2]") {
    const Mat2 m1;
    const Mat2 m2{ 2.5f, 1.5f, 1.0f, 2.0f };

    REQUIRE(m1.e_00 == Approx(1.0f));
    REQUIRE(m1.e_01 == Approx(0.0f));
    REQUIRE(m1.e_10 == Approx(0.0f));
    REQUIRE(m1.e_11 == Approx(1.0f));
    REQUIRE(m2.e_00 == Approx(2.5f));
    REQUIRE(m2.e_01 == Approx(1.5f));
    REQUIRE(m2.e_10 == Approx(1.0f));
    REQUIRE(m2.e_11 == Approx(2.0f));

}

// operator*= (mat2)
TEST_CASE("describe_operator*=", "[multiplication mat2]") {
    Mat2 m1;
    Mat2 m2{ 1.3f, -2.0f, 0.2f, 3.0f };
    const Mat2 m3{ 0.0f, 0.0f, -2.0f, 0.5f };

    m1 *= m2;
    m2 *= m3;
    const Mat2 m4 = m1 * m3;

    REQUIRE(m1.e_00 == Approx(1.3f));
    REQUIRE(m1.e_01 == Approx(-2.0f));
    REQUIRE(m1.e_10 == Approx(0.2f));
    REQUIRE(m1.e_11 == Approx(3.0f));
    REQUIRE(m2.e_00 == Approx(0.0f));
    REQUIRE(m2.e_01 == Approx(0.0f));
    REQUIRE(m2.e_10 == Approx(-2.5f));
    REQUIRE(m2.e_11 == Approx(5.5f));
    REQUIRE(m4.e_00 == Approx(0.0f));
    REQUIRE(m4.e_01 == Approx(0.0f));
    REQUIRE(m4.e_10 == Approx(-2.0f));
    REQUIRE(m4.e_11 == Approx(0.5f));

}

// Determinante
TEST_CASE("describe_determinant", "[determinant mat2]") {
    const Mat2 m1;
    const Mat2 m2{ 7.0f, 2.0f, 5.0f, 8.0f };
    const Mat2 m3{ 2.0f, 1.7f, 0.25f, 1.0f };

    REQUIRE(m1.det() == Approx(1.0f));
    REQUIRE(m2.det() == Approx(46.0f));
    REQUIRE(m3.det() == Approx(1.575f));

}



/* 
     VECTORS
 */

 // Initialisierung
TEST_CASE("describe_vec2", "[vec2]") {
    const Vec2 a;
    const Vec2 b{ 4.3f, -7.3f };
    const Vec2 c{ -1.0f, 5.0f };

    REQUIRE(a.x == Approx(0.0f));
    REQUIRE(a.y == Approx(0.0f));
    REQUIRE(b.x == Approx(4.3f));
    REQUIRE(b.y == Approx(-7.3f));
    REQUIRE(c.x == Approx(-1.0f));
    REQUIRE(c.y == Approx(5.0f));

}

// Addition
TEST_CASE("describe_addition_vec2", "[addition vec2]") {
    Vec2 v1;
    Vec2 v2{ 2.4f, 0.5f };
    const Vec2 v3{ 6.0f, -4.3f };

    v1 += v2;
    v2 += v3;

    REQUIRE(v1.x == Approx(2.4f));
    REQUIRE(v1.y == Approx(0.5f));
    REQUIRE(v2.x == Approx(8.4f));
    REQUIRE(v2.y == Approx(-3.8f));

}

// Multiplikation
TEST_CASE("describe_multiplication_vec2", "[multiplication vec2]") {
    Vec2 v1;
    Vec2 v2{ 3.1f, 4.0f };
    Vec2 v3{ -8.5f, 0.1f };
    const float s = 4;

    v1 *= s;
    v2 *= s;
    v3 *= s;

    REQUIRE(v1.x == Approx(0.0f));
    REQUIRE(v1.y == Approx(0.0f));
    REQUIRE(v2.x == Approx(12.4f));
    REQUIRE(v2.y == Approx(16.0f));
    REQUIRE(v3.x == Approx(-34.0f));
    REQUIRE(v3.y == Approx(0.4f));

}

// Subtraktion
TEST_CASE("describe_substraction_vec2", "[subtraction vec2]") {
    Vec2 v1{ 6.0f, 0.7f };
    Vec2 v2;
    const Vec2 v3{ 3.7f, -2.1f };

    v1 -= v2;
    v2 -= v3;

    REQUIRE(v1.x == Approx(6.0f));
    REQUIRE(v1.y == Approx(0.7f));
    REQUIRE(v2.x == Approx(-3.7f));
    REQUIRE(v2.y == Approx(2.1f));

}

// Division
TEST_CASE("describe_division_vec2", "[division vec2]") {
    Vec2 v1{ 6.0f, 1.7f };
    Vec2 v2{ 4.0f, 0.3f };
    Vec2 v3{ 2.2f, -1.1f };
    const float s = 4;

    v1 /= s;
    v2 /= s;
    v3 /= s;

    REQUIRE(v1.x == Approx(1.5f));
    REQUIRE(v1.y == Approx(0.425f));
    REQUIRE(v2.x == Approx(1.0f));
    REQUIRE(v2.y == Approx(0.075f));
    REQUIRE(v3.x == Approx(0.55f));
    REQUIRE(v3.y == Approx(-0.275f));

}




/* 
    FREE  FUNCTIONS
*/

 // operator* (mat2)
TEST_CASE("describe_operator*", "[free multiplication mat2]") {
    const Mat2 m1;
    const Mat2 m2{ 0.5f, -6.0f, 3.1f, 5.0f };
    const Mat2 m3{ 0.0f, 0.0f, -3.0f, 0.4f };

    const Mat2 m4 = m1 * m2;
    const Mat2 m5 = m2 * m3;
    const Mat2 m6 = m4 * m5;

    REQUIRE(m4.e_00 == Approx(0.5f));
    REQUIRE(m4.e_01 == Approx(-6.0f));
    REQUIRE(m4.e_10 == Approx(3.1f));
    REQUIRE(m4.e_11 == Approx(5.0f));
    REQUIRE(m5.e_00 == Approx(0.0f));
    REQUIRE(m5.e_01 == Approx(0.0f));
    REQUIRE(m5.e_10 == Approx(-0.26f));
    REQUIRE(m5.e_11 == Approx(20.0f));
    REQUIRE(m6.e_00 == Approx(1.56f));
    REQUIRE(m6.e_01 == Approx(-120.0f));
    REQUIRE(m6.e_10 == Approx(-1.3f));
    REQUIRE(m6.e_11 == Approx(100.0f));

}

// operator* (Matrix, Vektor)
TEST_CASE("describe_free_operator*_mat_vec", "[multiplication mat2 vec2]") {
    const Mat2 m1;
    const Mat2 m2{ 0.5f, -6.0f, 3.1f, 5.0f };
    Vec2 v1;
    Vec2 v2{ 1.1f, -4.2f };

    v1 = m1 * v1;
    v2 = v2 * m2;

    REQUIRE(v1.x == Approx(0.0f));
    REQUIRE(v1.y == Approx(0.0f));
    REQUIRE(v2.x == Approx(25.75f));
    REQUIRE(v2.y == Approx(-17.59f));

}

// Inverse
TEST_CASE("describe_inverse", "[inverse mat2]") {
    const Mat2 m0;
    const Mat2 m1{ 6.0f, 3.0f, 2.3f, 8.0f };
    const Mat2 m2 = inverse(m0);
    const Mat2 m3 = inverse(m1);

    REQUIRE(m2.e_00 == Approx(1.0f));
    REQUIRE(m2.e_01 == Approx(0.0f));
    REQUIRE(m2.e_10 == Approx(0.0f));
    REQUIRE(m2.e_11 == Approx(1.0f));
    REQUIRE(m3.e_00 == Approx(0.194647f));
    REQUIRE(m3.e_01 == Approx(-0.072993f));
    REQUIRE(m3.e_10 == Approx(-0.055961f));
    REQUIRE(m3.e_11 == Approx(0.145985f));
}

// Transposition
TEST_CASE("describe_transpose", "[transpose mat2]") {
    const Mat2 m0;
    const Mat2 m1{ 5.0f, 6.0f, 7.0f, 8.0f };
    const Mat2 m2 = transpose(m0);
    const Mat2 m3 = transpose(m1);

    REQUIRE(m2.e_00 == Approx(1.0f));
    REQUIRE(m2.e_01 == Approx(0.0f));
    REQUIRE(m2.e_10 == Approx(0.0f));
    REQUIRE(m2.e_11 == Approx(1.0f));
    REQUIRE(m3.e_00 == Approx(5.0f));
    REQUIRE(m3.e_01 == Approx(7.0f));
    REQUIRE(m3.e_10 == Approx(6.0f));
    REQUIRE(m3.e_11 == Approx(8.0f));

}

// Rotation
TEST_CASE("describe_rotate", "[rotate mat2]") {
    const Mat2 m1 = make_rotation_mat2(90.0f);
    const Mat2 m2 = make_rotation_mat2(45.0f);

    REQUIRE(m1.e_00 == Approx(0.0f));
    REQUIRE(m1.e_01 == Approx(-1.0f));
    REQUIRE(m1.e_10 == Approx(1.0f));
    REQUIRE(m1.e_11 == Approx(0.0f));
    REQUIRE(m2.e_00 == Approx(0.707107f));
    REQUIRE(m2.e_01 == Approx(-0.707107f));
    REQUIRE(m2.e_10 == Approx(0.707107f));
    REQUIRE(m2.e_11 == Approx(0.707107f));
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);

}
