#include <catch2/catch_test_macros.hpp>

#include "bracketsched/seeding.hpp"

using namespace bracketsched;

TEST_CASE("bitCeil finds the smallest power of two >= n", "[seeding]") {
    REQUIRE(bitCeil(1) == 1);
    REQUIRE(bitCeil(2) == 2);
    REQUIRE(bitCeil(3) == 4);
    REQUIRE(bitCeil(4) == 4);
    REQUIRE(bitCeil(5) == 8);
    REQUIRE(bitCeil(6) == 8);
    REQUIRE(bitCeil(8) == 8);
    REQUIRE(bitCeil(9) == 16);
}

TEST_CASE("innerOuterSeedOrder matches the known reference sequences", "[seeding]") {
    // These exact sequences come from the research's citation of a
    // production bracket library's inner_outer implementation -- not
    // invented, and not bit-reversal (which produces a different order).
    REQUIRE(innerOuterSeedOrder(2) == std::vector<int>{1, 2});
    REQUIRE(innerOuterSeedOrder(4) == std::vector<int>{1, 4, 2, 3});
    REQUIRE(innerOuterSeedOrder(8) == std::vector<int>{1, 8, 4, 5, 2, 7, 3, 6});
    REQUIRE(innerOuterSeedOrder(16) ==
            std::vector<int>{1, 16, 8, 9, 4, 13, 5, 12, 2, 15, 7, 10, 3, 14, 6, 11});
}

TEST_CASE("every first-round pair sums to size + 1", "[seeding]") {
    for (std::size_t size : {2, 4, 8, 16, 32, 64}) {
        auto order = innerOuterSeedOrder(size);
        for (std::size_t i = 0; i < order.size(); i += 2) {
            REQUIRE(order[i] + order[i + 1] == static_cast<int>(size) + 1);
        }
    }
}

TEST_CASE("innerOuterSeedOrder rejects non-power-of-two sizes", "[seeding]") {
    REQUIRE_THROWS_AS(innerOuterSeedOrder(3), std::invalid_argument);
    REQUIRE_THROWS_AS(innerOuterSeedOrder(6), std::invalid_argument);
}
