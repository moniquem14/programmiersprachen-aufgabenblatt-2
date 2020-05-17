#include <catch.hpp>
#include <cmath>
#include "vec2.hpp"
//#include "mat2.hpp"
#include "mat2.hpp"
//#include "circle.hpp"
//#include "rectangle.hpp"
//#include "color.hpp"
@@ - 21, 12 + 21, 12 @@ TEST_CASE("describe_vec2", "[vec2]") {
    Vec2 b{ 5.1f, -9.3f };
    Vec2 c(-1.0f, 2.0f);

    REQUIRE(a.x_ == Approx(0.0f));
    REQUIRE(a.y_ == Approx(0.0f));
    REQUIRE(b.x_ == Approx(5.1f));
    REQUIRE(b.y_ == Approx(-9.3f));
    REQUIRE(c.x_ == Approx(-1.0f));
    REQUIRE(c.y_ == Approx(2.0f));
    REQUIRE(a.x == Approx(0.0f));
    REQUIRE(a.y == Approx(0.0f));
    REQUIRE(b.x == Approx(5.1f));
    REQUIRE(b.y == Approx(-9.3f));
    REQUIRE(c.x == Approx(-1.0f));
    REQUIRE(c.y == Approx(2.0f));

}

@@ - 39, 10 + 39, 10 @@ TEST_CASE("describe_addition_vec2", "[add]") {
    v1 += v2;
    v2 += v3;

    REQUIRE(v1.x_ == Approx(4.3f));
    REQUIRE(v1.y_ == Approx(1.5f));
    REQUIRE(v2.x_ == Approx(7.3f));
    REQUIRE(v2.y_ == Approx(-1.2f));
    REQUIRE(v1.x == Approx(4.3f));
    REQUIRE(v1.y == Approx(1.5f));
    REQUIRE(v2.x == Approx(7.3f));
    REQUIRE(v2.y == Approx(-1.2f));

}

@@ - 57, 12 + 57, 12 @@ TEST_CASE("describe_multiplication_vec2", "[multiply]") {
    v2 *= s;
    v3 *= s;

    REQUIRE(v1.x_ == Approx(0.0f));
    REQUIRE(v1.y_ == Approx(0.0f));
    REQUIRE(v2.x_ == Approx(5.2f));
    REQUIRE(v2.y_ == Approx(8.0f));
    REQUIRE(v3.x_ == Approx(-5.6f));
    REQUIRE(v3.y_ == Approx(0.6f));
    REQUIRE(v1.x == Approx(0.0f));
    REQUIRE(v1.y == Approx(0.0f));
    REQUIRE(v2.x == Approx(5.2f));
    REQUIRE(v2.y == Approx(8.0f));
    REQUIRE(v3.x == Approx(-5.6f));
    REQUIRE(v3.y == Approx(0.6f));

}

@@ - 75, 10 + 75, 10 @@ TEST_CASE("describe_substraction_vec2", "[substract]") {
    v1 -= v2;
    v2 -= v3;

    REQUIRE(v1.x_ == Approx(3.0f));
    REQUIRE(v1.y_ == Approx(1.3f));
    REQUIRE(v2.x_ == Approx(-6.3f));
    REQUIRE(v2.y_ == Approx(4.7f));
    REQUIRE(v1.x == Approx(3.0f));
    REQUIRE(v1.y == Approx(1.3f));
    REQUIRE(v2.x == Approx(-6.3f));
    REQUIRE(v2.y == Approx(4.7f));

}

@@ - 93, 16 + 93, 30 @@ TEST_CASE("describe_division_vec2", "[divide]") {
    v2 /= s;
    v3 /= s;

    REQUIRE(v1.x_ == Approx(4.0f));
    REQUIRE(v1.y_ == Approx(2.3f));
    REQUIRE(v2.x_ == Approx(1.0f));
    REQUIRE(v2.y_ == Approx(0.65f));
    REQUIRE(v3.x_ == Approx(0.55f));
    REQUIRE(v3.y_ == Approx(-1.65f));
    REQUIRE(v1.x == Approx(4.0f));
    REQUIRE(v1.y == Approx(2.3f));
    REQUIRE(v2.x == Approx(1.0f));
    REQUIRE(v2.y == Approx(0.65f));
    REQUIRE(v3.x == Approx(0.55f));
    REQUIRE(v3.y == Approx(-1.65f));

}

// testing the correct initialization of instances
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


int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);

}