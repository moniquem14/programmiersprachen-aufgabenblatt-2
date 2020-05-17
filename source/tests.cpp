#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "vec2.hpp"
#include "mat2.hpp"
//#include "circle.hpp"
//#include "rectangle.hpp"
//#include "color.hpp"


/* ---------------------
 *    V E C T O R S
 * --------------------*/

 // testing initialization of instances
TEST_CASE("describe_vec2", "[vec2]") {
    const Vec2 a;
    const Vec2 b{ 5.1f, -9.3f };
    const Vec2 c(-1.0f, 2.0f);

    REQUIRE(a.x == Approx(0.0f));
    REQUIRE(a.y == Approx(0.0f));
    REQUIRE(b.x == Approx(5.1f));
    REQUIRE(b.y == Approx(-9.3f));
    REQUIRE(c.x == Approx(-1.0f));
    REQUIRE(c.y == Approx(2.0f));

}

// testing addition of vec2
TEST_CASE("describe_addition_vec2", "[addition vec2]") {
    Vec2 v1;
    Vec2 v2{ 4.3f, 1.5f };
    const Vec2 v3{ 3.0f, -2.7f };

    v1 += v2;
    v2 += v3;

    REQUIRE(v1.x == Approx(4.3f));
    REQUIRE(v1.y == Approx(1.5f));
    REQUIRE(v2.x == Approx(7.3f));
    REQUIRE(v2.y == Approx(-1.2f));

}

// testing multiplication of vec2
TEST_CASE("describe_multiplication_vec2", "[multiplication vec2]") {
    Vec2 v1;
    Vec2 v2{ 2.6f, 4.0f };
    Vec2 v3{ -2.8f, 0.3f };
    const float s = 2;

    v1 *= s;
    v2 *= s;
    v3 *= s;

    REQUIRE(v1.x == Approx(0.0f));
    REQUIRE(v1.y == Approx(0.0f));
    REQUIRE(v2.x == Approx(5.2f));
    REQUIRE(v2.y == Approx(8.0f));
    REQUIRE(v3.x == Approx(-5.6f));
    REQUIRE(v3.y == Approx(0.6f));

}

// testing substraction of vec2
TEST_CASE("describe_substraction_vec2", "[subtraction vec2]") {
    Vec2 v1{ 3.0f, 1.3f };
    Vec2 v2;
    const Vec2 v3{ 6.3f, -4.7f };

    v1 -= v2;
    v2 -= v3;

    REQUIRE(v1.x == Approx(3.0f));
    REQUIRE(v1.y == Approx(1.3f));
    REQUIRE(v2.x == Approx(-6.3f));
    REQUIRE(v2.y == Approx(4.7f));

}

// testing division of vec2
TEST_CASE("describe_division_vec2", "[division vec2]") {
    Vec2 v1{ 8.0f, 4.6f };
    Vec2 v2{ 2.0f, 1.3f };
    Vec2 v3{ 1.1f, -3.3f };
    const float s = 2;

    v1 /= s;
    v2 /= s;
    v3 /= s;

    REQUIRE(v1.x == Approx(4.0f));
    REQUIRE(v1.y == Approx(2.3f));
    REQUIRE(v2.x == Approx(1.0f));
    REQUIRE(v2.y == Approx(0.65f));
    REQUIRE(v3.x == Approx(0.55f));
    REQUIRE(v3.y == Approx(-1.65f));

}

/* ---------------------
 *    M A T R I C E S
 * --------------------*/

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

// testing operator*= of mat2
TEST_CASE("describe_operator*=", "[multiplication mat2]") {
    Mat2 m1;
    Mat2 m2{ 2.5f, -4.0f, 1.2f, 3.0f };
    const Mat2 m3{ 0.0f, 0.0f, -1.0f, 0.2f };

    m1 *= m2;
    m2 *= m3;
    const Mat2 m4 = m1 * m2;

    REQUIRE(m1.e_00 == Approx(2.5f));
    REQUIRE(m1.e_01 == Approx(-4.0f));
    REQUIRE(m1.e_10 == Approx(1.2f));
    REQUIRE(m1.e_11 == Approx(3.0f));
    REQUIRE(m2.e_00 == Approx(4.0f));
    REQUIRE(m2.e_01 == Approx(-0.8f));
    REQUIRE(m2.e_10 == Approx(-3.0f));
    REQUIRE(m2.e_11 == Approx(0.6f));
    REQUIRE(m4.e_00 == Approx(22.0f));
    REQUIRE(m4.e_01 == Approx(-4.4f));
    REQUIRE(m4.e_10 == Approx(-4.2f));
    REQUIRE(m4.e_11 == Approx(0.84f));

}

// testing determinant of mat2
TEST_CASE("describe_determinant", "[determinant mat2]") {
    const Mat2 m1;
    const Mat2 m2{ 2.0f, 6.0f, 8.0f, 3.0f };
    const Mat2 m3{ 4.0f, 6.3f, 0.4f, 2.0f };

    REQUIRE(m1.det() == Approx(1.0f));
    REQUIRE(m2.det() == Approx(-42.0f));
    REQUIRE(m3.det() == Approx(5.48f));

}


/* -------------------------------
 *   F R E E  F U N C T I O N S
 * ------------------------------*/

 // testing operator* of mat2
TEST_CASE("describe_operator*", "[free multiplication mat2]") {
    const Mat2 m1;
    const Mat2 m2{ 2.5f, -4.0f, 1.2f, 3.0f };
    const Mat2 m3{ 0.0f, 0.0f, -1.0f, 0.2f };

    const Mat2 m4 = m1 * m2;
    const Mat2 m5 = m2 * m3;
    const Mat2 m6 = m4 * m5;

    REQUIRE(m4.e_00 == Approx(2.5f));
    REQUIRE(m4.e_01 == Approx(-4.0f));
    REQUIRE(m4.e_10 == Approx(1.2f));
    REQUIRE(m4.e_11 == Approx(3.0f));
    REQUIRE(m5.e_00 == Approx(4.0f));
    REQUIRE(m5.e_01 == Approx(-0.8f));
    REQUIRE(m5.e_10 == Approx(-3.0f));
    REQUIRE(m5.e_11 == Approx(0.6f));
    REQUIRE(m6.e_00 == Approx(22.0f));
    REQUIRE(m6.e_01 == Approx(-4.4f));
    REQUIRE(m6.e_10 == Approx(-4.2f));
    REQUIRE(m6.e_11 == Approx(0.84f));

}

// testing operator* of matrix and vector and vice versa
TEST_CASE("describe_free_operator*_mat_vec", "[multiplication mat2 vec2]") {
    const Mat2 m1;
    const Mat2 m2{ 2.5f, -4.0f, 1.2f, 3.0f };
    Vec2 v1;
    Vec2 v2{ 5.1f, -9.3f };

    v1 = m1 * v1;
    v2 = v2 * m2;

    REQUIRE(v1.x == Approx(0.0f));
    REQUIRE(v1.y == Approx(0.0f));
    REQUIRE(v2.x == Approx(49.95f));
    REQUIRE(v2.y == Approx(-21.78f));

}

// testing inverse of mat2
TEST_CASE("describe_inverse", "[inverse mat2]") {
    const Mat2 m0;
    const Mat2 m1{ 3.0f, 5.0f, 3.5f, 6.0f };
    const Mat2 m2 = inverse(m0);
    const Mat2 m3 = inverse(m1);

    REQUIRE(m2.e_00 == Approx(1.0f));
    REQUIRE(m2.e_01 == Approx(0.0f));
    REQUIRE(m2.e_10 == Approx(0.0f));
    REQUIRE(m2.e_11 == Approx(1.0f));
    REQUIRE(m3.e_00 == Approx(12.0f));
    REQUIRE(m3.e_01 == Approx(-10.0f));
    REQUIRE(m3.e_10 == Approx(-7.0f));
    REQUIRE(m3.e_11 == Approx(6.0f));
}

// testing transpose of mat2
TEST_CASE("describe_transpose", "[transpose mat2]") {
    const Mat2 m0;
    const Mat2 m1{ 1.0f, 2.0f, 3.0f, 4.0f };
    const Mat2 m2 = transpose(m0);
    const Mat2 m3 = transpose(m1);

    REQUIRE(m2.e_00 == Approx(1.0f));
    REQUIRE(m2.e_01 == Approx(0.0f));
    REQUIRE(m2.e_10 == Approx(0.0f));
    REQUIRE(m2.e_11 == Approx(1.0f));
    REQUIRE(m3.e_00 == Approx(1.0f));
    REQUIRE(m3.e_01 == Approx(3.0f));
    REQUIRE(m3.e_10 == Approx(2.0f));
    REQUIRE(m3.e_11 == Approx(4.0f));

}

// testing rotation of mat2
TEST_CASE("describe_rotate", "[rotate mat2]") {
    const Mat2 m1 = make_rotation_mat2(90.0f);
    const Mat2 m2 = make_rotation_mat2(45.0f);

    REQUIRE(m1.e_00 == Approx(-0.44807f));
    REQUIRE(m1.e_01 == Approx(-0.894f));
    REQUIRE(m1.e_10 == Approx(0.894f));
    REQUIRE(m1.e_11 == Approx(-0.44807f));
    REQUIRE(m2.e_00 == Approx(0.52532f));
    REQUIRE(m2.e_01 == Approx(-0.8509f));
    REQUIRE(m2.e_10 == Approx(0.8509f));
    REQUIRE(m2.e_11 == Approx(0.52532f));
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);

}
