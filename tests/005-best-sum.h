#ifndef TESTS_005_H

#define TESTS_005_H

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "problems/005-bestSum/main.h"

TEST_CASE("[005-bestSum] DP implementation - unoptimized...", "[005-bestSum]") {
    CHECK(bestSum_dp(2, { 1, 2 }) == vector<uint64_t>{ 2 });
    CHECK(bestSum_dp(7, { 5, 1, 2, 3, 4 }) == vector<uint64_t>{ 5, 2 });
    CHECK(bestSum_dp(7, { 5, 3, 4, 7 }) == vector<uint64_t>{ 7 });
    CHECK(bestSum_dp(8, { 2, 3, 5 }) == vector<uint64_t>{ 3, 5 });
    CHECK(bestSum_dp(8, { 1, 4, 5 }) == vector<uint64_t>{ 4, 4 });
    CHECK(bestSum_dp(18, { 1, 2, 3, 4, 5, 6, 7 }) == vector<uint64_t>{ 4, 7, 7 });
    //CHECK(bestSum_dp(100, { 1, 2, 5, 15 }) == vector<uint64_t>{ 3, 4 });
};

#endif
