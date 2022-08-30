#ifndef TESTS_003_H

#define TESTS_003_H

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "problems/003-canSum/main.h"

TEST_CASE("[003-canSum] DP implementation - unoptimized...", "[003-canSum]") {
    CHECK(canSum_dp(7, { 2, 3 }) == true);
    CHECK(canSum_dp(7, { 5, 3, 4, 7 }) == true);
    CHECK(canSum_dp(7, { 2, 4 }) == false);
    CHECK(canSum_dp(8, { 2, 3, 5 }) == true);
    CHECK(canSum_dp(100, { 7, 14 }) == false);
}

TEST_CASE("[003-canSum] DP implementation - memoization pattern...", "003-canSum") {
    CHECK(canSum_dp_memo(7, { 2, 3 }) == true);
    CHECK(canSum_dp_memo(7, { 5, 3, 4, 7 }) == true);
    CHECK(canSum_dp_memo(7, { 2, 4 }) == false);
    CHECK(canSum_dp_memo(8, { 2, 3, 5 }) == true);
    CHECK(canSum_dp_memo(100, { 7, 14 }) == false);
    CHECK(canSum_dp_memo(10000, {1, 1, 1, 1, 1 }) == true);
}

TEST_CASE("[003-canSum] DP implementation - tabulation pattern...", "003-canSum") {
    CHECK(canSum_dp_tab(7, { 2, 3 }) == true);
    CHECK(canSum_dp_tab(7, { 5, 3, 4, 7 }) == true);
    CHECK(canSum_dp_tab(7, { 2, 4 }) == false);
    CHECK(canSum_dp_tab(8, { 2, 3, 5 }) == true);
    CHECK(canSum_dp_tab(100, { 7, 14 }) == false);
    CHECK(canSum_dp_tab(10000, { 1, 1, 1, 1, 1 }) == true);
}

#if RUN_BENCHMARKS == 1

TEST_CASE("[003-canSum] Benchmarks...") {

    BENCHMARK("DP - Unoptimized") {
        return canSum_dp(100, { 7, 14 });
    };

    BENCHMARK("DP - Memoization") {
        return canSum_dp_memo(100, { 7, 14 });
    };

    BENCHMARK("DP - Tabulation") {
        return canSum_dp_tab(100, { 7, 14 });
    };
};

#endif

#endif
