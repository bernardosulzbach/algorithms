#include "catch.hpp"

#include "point.hpp"
#include "distance.hpp"

using algorithms::Point;
using algorithms::closest_pair_of_points;

TEST_CASE("closest_pair_of_points with less than two points") {
    // Should return a pair of default-initialized points.
    std::vector<Point> points;
    std::pair<Point, Point> expected = std::make_pair(Point(), Point());
    REQUIRE(expected == closest_pair_of_points(points.begin(), points.end()));
    points.push_back(Point(1.0, 1.0));
    REQUIRE(expected == closest_pair_of_points(points.begin(), points.end()));
}

TEST_CASE("closest_pair_of_points base case") {
    std::vector<Point> points;

    points.push_back(Point(0.0, 0.0));
    points.push_back(Point(1.0, 1.0));
    std::pair<Point, Point> expected = std::make_pair(points[0], points[1]);
    REQUIRE(expected == closest_pair_of_points(points.begin(), points.end()));

    points.push_back(Point(1.6, 1.6));
    expected = std::make_pair(points[1], points[2]);
    REQUIRE(expected == closest_pair_of_points(points.begin(), points.end()));

    points.push_back(Point(1.6, 2.0));
    expected = std::make_pair(points[2], points[3]);
    REQUIRE(expected == closest_pair_of_points(points.begin(), points.end()));

    points.push_back(Point(1.8, 2.0));
    expected = std::make_pair(points[3], points[4]);
    REQUIRE(expected == closest_pair_of_points(points.begin(), points.end()));
}

TEST_CASE("minimum_distance base case") {
    std::vector<Point> points;

    points.push_back(Point(0, 0));
    points.push_back(Point(1, 0));
    REQUIRE(1 == algorithms::minimum_distance(points.begin(), points.end()));

    points.push_back(Point(0, 0.625));
    REQUIRE(0.625 == algorithms::minimum_distance(points.begin(), points.end()));
}