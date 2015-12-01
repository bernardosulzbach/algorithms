#include "catch.hpp"

#include "point.hpp"

using algorithms::Point;

TEST_CASE("Point < comparator") {
    Point a(0, 0);
    Point b(0, 1);
    Point c(1, 0);
    Point d(1, 1);
    REQUIRE(a < b);
    REQUIRE(a < c);
    REQUIRE(a < d);
    REQUIRE(!(b < a));
    REQUIRE(!(c < a));
    REQUIRE(!(c < b));
    REQUIRE(!(d < a));
    REQUIRE(!(d < b));
    REQUIRE(!(d < c));
}
