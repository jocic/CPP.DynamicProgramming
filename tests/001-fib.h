#ifndef TESTS_001_H

#define TESTS_001_H

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "problems/001-fib/main.h"

TEST_CASE("[001-fib] DP implementation - unoptimized...", "001-fib") {
    CHECK(fib_dp(1) == 1);
    CHECK(fib_dp(4) == 3);
    CHECK(fib_dp(8) == 21);
    CHECK(fib_dp(16) == 987);
}

TEST_CASE("[001-fib] DP implementation - memoization pattern...", "001-fib") {
    CHECK(fib_dp_memo(1) == 1);
    CHECK(fib_dp_memo(4) == 3);
    CHECK(fib_dp_memo(8) == 21);
    CHECK(fib_dp_memo(16) == 987);
    CHECK(fib_dp_memo(32) == 2178309);
    CHECK(fib_dp_memo(64) == 10610209857723);
}

TEST_CASE("[001-fib] DP implementation - tabulation pattern...", "001-fib") {
    CHECK(fib_dp_tab(1) == 1);
    CHECK(fib_dp_tab(4) == 3);
    CHECK(fib_dp_tab(8) == 21);
    CHECK(fib_dp_tab(16) == 987);
    CHECK(fib_dp_tab(32) == 2178309);
    CHECK(fib_dp_tab(64) == 10610209857723);
}

TEST_CASE("[001-fib] Arbitrary implementation...", "001-fib") {
    CHECK(fib_reg(1) == 1);
    CHECK(fib_reg(4) == 3);
    CHECK(fib_reg(8) == 21);
    CHECK(fib_reg(16) == 987);
    CHECK(fib_reg(32) == 2178309);
    CHECK(fib_reg(64) == 10610209857723);
}

#if RUN_BENCHMARKS == 1

TEST_CASE("[001-fib] Benchmarks...") {

    BENCHMARK("DP - Unoptimized") {
        return fib_dp(16);
    };

    BENCHMARK("DP - Memoization") {
        return fib_dp_memo(16);
    };

    BENCHMARK("DP - Tabulation") {
        return fib_dp_tab(16);
    };

    BENCHMARK("DP - General") {
        return fib_reg(16);
    };
};

#endif

#endif
