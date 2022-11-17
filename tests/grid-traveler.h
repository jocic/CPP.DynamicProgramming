#ifndef TESTS_GRID_TRAVELER_H

#define TESTS_GRID_TRAVELER_H

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "problems/grid-traveler/main.h"

TEST_CASE("[002-gridTraveler] DP implementation - unoptimized...") {
    CHECK(gridTraveler_dp(1, 0) == 0);
    CHECK(gridTraveler_dp(1, 1) == 1);
    CHECK(gridTraveler_dp(1, 2) == 1);
    CHECK(gridTraveler_dp(2, 3) == 3);
    CHECK(gridTraveler_dp(3, 2) == 3);
    CHECK(gridTraveler_dp(4, 4) == 20);
    CHECK(gridTraveler_dp(8, 8) == 3432);
}

TEST_CASE("[002-gridTraveler] DP implementation - memoization pattern...") {
    CHECK(gridTraveler_dp_memo(1, 0) == 0);
    CHECK(gridTraveler_dp_memo(1, 1) == 1);
    CHECK(gridTraveler_dp_memo(1, 2) == 1);
    CHECK(gridTraveler_dp_memo(2, 3) == 3);
    CHECK(gridTraveler_dp_memo(3, 2) == 3);
    CHECK(gridTraveler_dp_memo(4, 4) == 20);
    CHECK(gridTraveler_dp_memo(8, 8) == 3432);
}

TEST_CASE("[002-gridTraveler] DP implementation - tabulation pattern...") {
    CHECK(gridTraveler_dp_tab(1, 0) == 0);
    CHECK(gridTraveler_dp_tab(1, 1) == 1);
    CHECK(gridTraveler_dp_tab(1, 2) == 1);
    CHECK(gridTraveler_dp_tab(2, 3) == 3);
    CHECK(gridTraveler_dp_tab(3, 2) == 3);
    CHECK(gridTraveler_dp_tab(4, 4) == 20);
    CHECK(gridTraveler_dp_tab(8, 8) == 3432);
}

#if RUN_BENCHMARKS == 1

TEST_CASE("[002-gridTraveler] Benchmarks...") {

    BENCHMARK("Unoptimized") {
        return gridTraveler_dp(8, 8);
    };

    BENCHMARK("Memoization") {
        return gridTraveler_dp_memo(8, 8);
    };

    BENCHMARK("Tabulation") {
        return gridTraveler_dp_tab(8, 8);
    };
};

#endif

#endif
