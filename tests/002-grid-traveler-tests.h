#ifndef GRID_TRAVELER_TESTS_H

#define GRID_TRAVELER_TESTS_H

#include <catch2/catch_test_macros.hpp>

#include "../002-gridTraveler/main.h"

TEST_CASE("[002-gridTraveler] DP implementation - unoptimized...", "002-gridTraveler") {
    REQUIRE(gridTraveler_dp(1, 0) == 0);
    REQUIRE(gridTraveler_dp(1, 1) == 1);
    REQUIRE(gridTraveler_dp(1, 2) == 1);
    REQUIRE(gridTraveler_dp(2, 3) == 3);
    REQUIRE(gridTraveler_dp(3, 2) == 3);
    REQUIRE(gridTraveler_dp(4, 4) == 20);
    REQUIRE(gridTraveler_dp(8, 8) == 3432);
}

TEST_CASE("[002-gridTraveler] DP implementation - memoization pattern...", "002-gridTraveler") {
    REQUIRE(gridTraveler_dp_memo(1, 0) == 0);
    REQUIRE(gridTraveler_dp_memo(1, 1) == 1);
    REQUIRE(gridTraveler_dp_memo(1, 2) == 1);
    REQUIRE(gridTraveler_dp_memo(2, 3) == 3);
    REQUIRE(gridTraveler_dp_memo(3, 2) == 3);
    REQUIRE(gridTraveler_dp_memo(4, 4) == 20);
    REQUIRE(gridTraveler_dp_memo(8, 8) == 3432);
    REQUIRE(gridTraveler_dp_memo(18, 18) == 2333606220);
}

TEST_CASE("[002-gridTraveler] DP implementation - tabulation pattern...", "002-gridTraveler") {
    REQUIRE(gridTraveler_dp_tab(1, 0) == 0);
    REQUIRE(gridTraveler_dp_tab(1, 1) == 1);
    REQUIRE(gridTraveler_dp_tab(1, 2) == 1);
    REQUIRE(gridTraveler_dp_tab(2, 3) == 3);
    REQUIRE(gridTraveler_dp_tab(3, 2) == 3);
    REQUIRE(gridTraveler_dp_tab(4, 4) == 20);
    REQUIRE(gridTraveler_dp_tab(8, 8) == 3432);
    REQUIRE(gridTraveler_dp_tab(18, 18) == 2333606220);
}

#endif
