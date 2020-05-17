#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "vec2.hpp"
#include "mat2.hpp"
//#include "circle.hpp"
//#include "rectangle.hpp"
//#include "color.hpp"


/*
     V E C T O R S
*/

 // testing initialization of instances
TEST_CASE("describe_vec2", "[vec2]") {
    Vec2 a;
    Vec2 b{ 5.1f, -9.3f };
    Vec2 c(-1.0f, 2.0f);

    REQUIRE(a.x == Approx(0.0f));
    REQUIRE(a.y == Approx(0.0f));
    REQUIRE(b.x == Approx(5.1f));
    REQUIRE(b.y == Approx(-9.3f));
    REQUIRE(c.x == Approx(-1.0f));
    REQUIRE(c.y == Approx(2.0f));

}

// testing addition of vec2
TEST_CASE("describe_addition_vec2", "[add]") {
    Vec2 v1;
    Vec2 v2{ 4.3f, 1.5f };
    Vec2 v3{ 3.0f, -2.7f };

    v1 += v2;
    v2 += v3;

    REQUIRE(v1.x == Approx(4.3f));
    REQUIRE(v1.y == Approx(1.5f));
    REQUIRE(v2.x == Approx(7.3f));
    REQUIRE(v2.y == Approx(-1.2f));

}

// testing multiplication of vec2
TEST_CASE("describe_multiplication_vec2", "[multiply]") {
    Vec2 v1;
    Vec2 v2{ 2.6f, 4.0f };
    Vec2 v3{ -2.8f, 0.3f };
    float s = 2;

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
TEST_CASE("describe_substraction_vec2", "[substract]") {
    Vec2 v1{ 3.0f, 1.3f };
    Vec2 v2;
    Vec2 v3{ 6.3f, -4.7f };

    v1 -= v2;
    v2 -= v3;

    REQUIRE(v1.x == Approx(3.0f));
    REQUIRE(v1.y == Approx(1.3f));
    REQUIRE(v2.x == Approx(-6.3f));
    REQUIRE(v2.y == Approx(4.7f));

}

// testing division of vec2
TEST_CASE("describe_division_vec2", "[divide]") {
    Vec2 v1{ 8.0f, 4.6f };
    Vec2 v2{ 2.0f, 1.3f };
    Vec2 v3{ 1.1f, -3.3f };
    float s = 2;

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

/*
     M A T R I C E S
 */

 // testing initialization of instances
TEST_CASE("describe_mat2", "[mat2]") {
    Mat2 m1;
    Mat2 m2{ 2.5f, 1.5f, 1.0f, 2.0f };

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
TEST_CASE("describe_operator*=", "[mat2]") {
    Mat2 m1;
    Mat2 m2{ 2.5f, -4.0f, 1.2f, 3.0f };
    Mat2 m3{ 0.0f, 0.0f, -1.0f, 0.2f };

    m1 *= m2;
    m2 *= m3;
    Mat2 m4 = m1 * m2;

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

// testing free operator* of mat2
TEST_CASE("describe_operator*", "[mat2]") {
    Mat2 m1;
    Mat2 m2{ 2.5f, -4.0f, 1.2f, 3.0f };
    Mat2 m3{ 0.0f, 0.0f, -1.0f, 0.2f };

    Mat2 m4 = m1 * m2;
    Mat2 m5 = m2 * m3;
    Mat2 m6 = m4 * m5;

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





int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);


}