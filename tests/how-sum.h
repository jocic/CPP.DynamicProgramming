#ifndef TESTS_HOW_SUM_H

#define TESTS_HOW_SUM_H

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "problems/how-sum/main.h"

TEST_CASE("[how-sum] DP implementation - unoptimized...") {
    CHECK(how_sum_dp(5, { 1 }) == vector<int>{ 1, 1, 1, 1, 1 });
    CHECK(how_sum_dp(7, { 2, 3 }) == vector<int>{ 3, 2, 2 });
    CHECK(how_sum_dp(7, { 3, 2 }) == vector<int>{ 2, 2, 3 });
    CHECK(how_sum_dp(7, { 5, 3, 4, 7 }) == vector<int>{ 4, 3 });
    CHECK(how_sum_dp(8, { 2, 3, 5 }) == vector<int>{ 2, 2, 2, 2 });
    CHECK(how_sum_dp(100, { 7, 14 }) == vector<int>{ });
    CHECK(how_sum_dp(100, { 7, 14 }) == vector<int>{ });
    CHECK(how_sum_dp(100, { 7, 14, 2 }) == vector<int>{ 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 });
}

TEST_CASE("[how-sum] DP implementation - Memoization pattern...") {
    CHECK(how_sum_dp_memo(5, { 1 }) == vector<int>{ 1, 1, 1, 1, 1 });
    CHECK(how_sum_dp_memo(7, { 2, 3 }) == vector<int>{ 3, 2, 2 });
    CHECK(how_sum_dp_memo(7, { 3, 2 }) == vector<int>{ 2, 2, 3 });
    CHECK(how_sum_dp_memo(7, { 5, 3, 4, 7 }) == vector<int>{ 4, 3 });
    CHECK(how_sum_dp_memo(8, { 2, 3, 5 }) == vector<int>{ 2, 2, 2, 2 });
    CHECK(how_sum_dp_memo(100, { 7, 14 }) == vector<int>{ });
    CHECK(how_sum_dp_memo(100, { 7, 14, 2 }) == vector<int>{ 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 });
}

TEST_CASE("[how-sum] DP implementation - Tabulation pattern...") {
    CHECK(how_sum_dp_tab(5, { 1 }) == vector<int>{ 1, 1, 1, 1, 1 });
    CHECK(how_sum_dp_tab(7, { 2, 3 }) == vector<int>{ 2, 2, 3 });
    CHECK(how_sum_dp_tab(7, { 3, 2 }) == vector<int>{ 2, 2, 3 });
    CHECK(how_sum_dp_tab(7, { 5, 3, 4, 7 }) == vector<int>{ 7 });
    CHECK(how_sum_dp_tab(8, { 2, 3, 5 }) == vector<int>{ 3, 5 });
    CHECK(how_sum_dp_tab(100, { 7, 14 }) == vector<int>{ });
}

#if RUN_BENCHMARKS == 1

TEST_CASE("[how-sum] Benchmarks...") {

    BENCHMARK("Unoptimized") {
        return how_sum_dp(100, { 1, 2, 3, 4 });
    };

    BENCHMARK("Memoization") {
        return how_sum_dp_memo(100, { 1, 2, 3, 4 });
    };

    BENCHMARK("Tabulation") {
        return how_sum_dp_tab(100, { 1, 2, 3, 4 });
    };
}

#endif

#endif
