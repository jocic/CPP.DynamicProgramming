#ifndef TESTS_FIB_H

#define TESTS_FIB_H

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "problems/fib/main.h"

TEST_CASE("[001-fib] DP implementation - unoptimized...") {
    CHECK(fib_dp(1) == 1);
    CHECK(fib_dp(4) == 3);
    CHECK(fib_dp(8) == 21);
    CHECK(fib_dp(16) == 987);
}

TEST_CASE("[001-fib] DP implementation - memoization pattern...") {
    CHECK(fib_dp_memo(1) == 1);
    CHECK(fib_dp_memo(4) == 3);
    CHECK(fib_dp_memo(8) == 21);
    CHECK(fib_dp_memo(16) == 987);
    CHECK(fib_dp_memo(32) == 2178309);
}

TEST_CASE("[001-fib] DP implementation - tabulation pattern...") {
    CHECK(fib_dp_tab(1) == 1);
    CHECK(fib_dp_tab(4) == 3);
    CHECK(fib_dp_tab(8) == 21);
    CHECK(fib_dp_tab(16) == 987);
    CHECK(fib_dp_tab(32) == 2178309);
}

TEST_CASE("[001-fib] Arbitrary implementation...") {
    CHECK(fib_reg(1) == 1);
    CHECK(fib_reg(4) == 3);
    CHECK(fib_reg(8) == 21);
    CHECK(fib_reg(16) == 987);
    CHECK(fib_reg(32) == 2178309);
}

#if RUN_BENCHMARKS == 1

TEST_CASE("[001-fib] Benchmarks...") {

    BENCHMARK("Unoptimized") {
        return fib_dp(16);
    };

    BENCHMARK("Memoization") {
        return fib_dp_memo(16);
    };

    BENCHMARK("Tabulation") {
        return fib_dp_tab(16);
    };

    BENCHMARK("General") {
        return fib_reg(16);
    };
};

#endif

#endif
