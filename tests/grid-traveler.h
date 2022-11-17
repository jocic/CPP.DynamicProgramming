#ifndef TESTS_GRID_TRAVELER_H

#define TESTS_GRID_TRAVELER_H

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "problems/grid-traveler/main.h"

TEST_CASE("grid-traveler] DP implementation - unoptimized...") {
    CHECK(grid_traveler_dp(1, 0) == 0);
    CHECK(grid_traveler_dp(1, 1) == 1);
    CHECK(grid_traveler_dp(1, 2) == 1);
    CHECK(grid_traveler_dp(2, 3) == 3);
    CHECK(grid_traveler_dp(3, 2) == 3);
    CHECK(grid_traveler_dp(4, 4) == 20);
    CHECK(grid_traveler_dp(8, 8) == 3432);
}

TEST_CASE("[grid-traveler] DP implementation - memoization pattern...") {
    CHECK(grid_traveler_dp_memo(1, 0) == 0);
    CHECK(grid_traveler_dp_memo(1, 1) == 1);
    CHECK(grid_traveler_dp_memo(1, 2) == 1);
    CHECK(grid_traveler_dp_memo(2, 3) == 3);
    CHECK(grid_traveler_dp_memo(3, 2) == 3);
    CHECK(grid_traveler_dp_memo(4, 4) == 20);
    CHECK(grid_traveler_dp_memo(8, 8) == 3432);
}

TEST_CASE("[grid-traveler] DP implementation - tabulation pattern...") {
    CHECK(grid_traveler_dp_tab(1, 0) == 0);
    CHECK(grid_traveler_dp_tab(1, 1) == 1);
    CHECK(grid_traveler_dp_tab(1, 2) == 1);
    CHECK(grid_traveler_dp_tab(2, 3) == 3);
    CHECK(grid_traveler_dp_tab(3, 2) == 3);
    CHECK(grid_traveler_dp_tab(4, 4) == 20);
    CHECK(grid_traveler_dp_tab(8, 8) == 3432);
}

#if RUN_BENCHMARKS == 1

TEST_CASE("[grid-traveler] Benchmarks...") {

    BENCHMARK("Unoptimized") {
        return grid_traveler_dp(8, 8);
    };

    BENCHMARK("Memoization") {
        return grid_traveler_dp_memo(8, 8);
    };

    BENCHMARK("Tabulation") {
        return grid_traveler_dp_tab(8, 8);
    };
};

#endif

#endif
