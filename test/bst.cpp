#include "catch.hpp"

#include "bst.hpp"

namespace algorithms {
    TEST_CASE("binary search tree test") {
        BinarySearchTree<int> tree;
        std::vector<int> values = {0, 2, 3, 5, 8};
        const int minimum = 0;
        const int maximum = 8;
        for (int value : values) tree.insert(value);
        for (int i = 0; i < 10; ++i) {
            REQUIRE((std::find(values.begin(), values.end(), i) != values.end()) == tree.contains(i));
        }
        REQUIRE(minimum == tree.min());
        REQUIRE(maximum == tree.max());
    }
}