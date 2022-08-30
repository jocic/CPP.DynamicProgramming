#ifndef TESTS_004_H

#define TESTS_004_H

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "problems/004-howSum/main.h"

TEST_CASE("[004-howSum] DP implementation - unoptimized...", "[004-howSum]") {
    CHECK(how_sum_dp(5, { 1 }) == vector<uint64_t>{ 1, 1, 1, 1, 1 });
    CHECK(how_sum_dp(7, { 2, 3 }) == vector<uint64_t>{ 2, 2, 3 });
    CHECK(how_sum_dp(7, { 3, 2 }) == vector<uint64_t>{ 3, 2, 2 });
    CHECK(how_sum_dp(7, { 5, 3, 4, 7 }) == vector<uint64_t>{ 3, 4 });
    CHECK(how_sum_dp(8, { 2, 3, 5 }) == vector<uint64_t>{ 2, 2, 2, 2 });
    CHECK(how_sum_dp(100, { 7, 14 }) == vector<uint64_t>{ });
}

TEST_CASE("[004-howSum] DP implementation - Memoization pattern...", "[004-howSum]") {
    CHECK(how_sum_dp_memo(5, { 1 }) == vector<uint64_t>{ 1, 1, 1, 1, 1 });
    CHECK(how_sum_dp_memo(7, { 2, 3 }) == vector<uint64_t>{ 2, 2, 3 });
    CHECK(how_sum_dp_memo(7, { 3, 2 }) == vector<uint64_t>{ 3, 2, 2 });
    CHECK(how_sum_dp_memo(7, { 5, 3, 4, 7 }) == vector<uint64_t>{ 3, 4 });
    CHECK(how_sum_dp_memo(8, { 2, 3, 5 }) == vector<uint64_t>{ 2, 2, 2, 2 });
    CHECK(how_sum_dp_memo(100, { 7, 14 }) == vector<uint64_t>{ });
}

TEST_CASE("[004-howSum] DP implementation - Tabulation pattern...", "[004-howSum]") {
//    CHECK(how_sum_dp_tab(5, { 1 }) == vector<uint64_t>{ 1, 1, 1, 1, 1 });
    CHECK(how_sum_dp_tab(7, { 2, 3 }) == vector<uint64_t>{ 3, 2, 2 });
//    CHECK(how_sum_dp_tab(7, { 3, 2 }) == vector<uint64_t>{ 2, 2, 3 });
//    CHECK(how_sum_dp_tab(7, { 5, 3, 4, 7 }) == vector<uint64_t>{ 7 });
//    CHECK(how_sum_dp_tab(8, { 2, 3, 5 }) == vector<uint64_t>{ 2, 2, 2, 2 });
//    CHECK(how_sum_dp_tab(100, { 7, 14 }) == vector<uint64_t>{ });
}

#endif
