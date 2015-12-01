#include "catch.hpp"

#include "counting_sort.hpp"

TEST_CASE("counting_sort with no elements") {
    std::vector<int> empty_vector;
    algorithms::counting_sort<std::vector<int>::iterator, int>(empty_vector.begin(), empty_vector.end());
}

TEST_CASE("counting_sort with a single element") {
    std::vector<int> vector = {0};
    algorithms::counting_sort<std::vector<int>::iterator, int>(vector.begin(), vector.end());
}

TEST_CASE("counting_sort base case") {
    std::vector<int> sorted_vector = {1, 2, 3};
    std::vector<int> vector = {3, 2, 1};
    algorithms::counting_sort<std::vector<int>::iterator, int>(vector.begin(), vector.end());
    REQUIRE(std::equal(sorted_vector.begin(), sorted_vector.end(), vector.begin()));
}