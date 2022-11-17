#ifndef TESTS_CAN_SUM_H

#define TESTS_CAN_SUM_H

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "problems/can-sum/main.h"

TEST_CASE("[can-sum] DP implementation - unoptimized...") {
    CHECK(can_sum_dp(7, { 2, 3 }) == true);
    CHECK(can_sum_dp(7, { 5, 3, 4, 7 }) == true);
    CHECK(can_sum_dp(7, { 2, 4 }) == false);
    CHECK(can_sum_dp(8, { 2, 3, 5 }) == true);
    CHECK(can_sum_dp(100, { 7, 14 }) == false);
}

TEST_CASE("[can-sum] DP implementation - memoization pattern...") {
    CHECK(can_sum_dp_memo(7, { 2, 3 }) == true);
    CHECK(can_sum_dp_memo(7, { 5, 3, 4, 7 }) == true);
    CHECK(can_sum_dp_memo(7, { 2, 4 }) == false);
    CHECK(can_sum_dp_memo(8, { 2, 3, 5 }) == true);
    CHECK(can_sum_dp_memo(100, { 7, 14 }) == false);
    CHECK(can_sum_dp_memo(10000, {1, 1, 1, 1, 1 }) == true);
}

TEST_CASE("[can-sum] DP implementation - tabulation pattern...") {
    CHECK(can_sum_dp_tab(7, { 2, 3 }) == true);
    CHECK(can_sum_dp_tab(7, { 5, 3, 4, 7 }) == true);
    CHECK(can_sum_dp_tab(7, { 2, 4 }) == false);
    CHECK(can_sum_dp_tab(8, { 2, 3, 5 }) == true);
    CHECK(can_sum_dp_tab(100, { 7, 14 }) == false);
    CHECK(can_sum_dp_tab(10000, { 1, 1, 1, 1, 1 }) == true);
}

#if RUN_BENCHMARKS == 1

TEST_CASE("[can-sum] Benchmarks...") {

    BENCHMARK("Unoptimized") {
        return can_sum_dp(100, { 7, 14 });
    };

    BENCHMARK("Memoization") {
        return can_sum_dp_memo(100, { 7, 14 });
    };

    BENCHMARK("Tabulation") {
        return can_sum_dp_tab(100, { 7, 14 });
    };
};

#endif

#endif
