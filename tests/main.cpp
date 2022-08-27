#define CONFIG_CATCH_MAIN

#include <catch2/catch_test_macros.hpp>

#include "../001-fib/main.h"

/*******************\
|* 001-FIB Problem *|
\*******************/

TEST_CASE("[001-FIB] DP implementation - unoptimized...", "001-FIB") {
    REQUIRE(fib_dp(1) == 1);
    REQUIRE(fib_dp(4) == 3);
    REQUIRE(fib_dp(8) == 21);
    REQUIRE(fib_dp(16) == 987);
}

TEST_CASE("[001-FIB] DP implementation - memoization pattern...", "001-FIB") {
    REQUIRE(fib_dp_memo(1) == 1);
    REQUIRE(fib_dp_memo(4) == 3);
    REQUIRE(fib_dp_memo(8) == 21);
    REQUIRE(fib_dp_memo(16) == 987);
    REQUIRE(fib_dp_memo(32) == 2178309);
    REQUIRE(fib_dp_memo(64) == 10610209857723);
}

TEST_CASE("[001-FIB] DP implementation - tabulation pattern...", "001-FIB") {
    REQUIRE(fib_dp_tab(1) == 1);
    REQUIRE(fib_dp_tab(4) == 3);
    REQUIRE(fib_dp_tab(8) == 21);
    REQUIRE(fib_dp_tab(16) == 987);
    REQUIRE(fib_dp_tab(32) == 2178309);
    REQUIRE(fib_dp_tab(64) == 10610209857723);
}

TEST_CASE("[001-FIB] Arbitrary implementation...", "001-FIB") {
    REQUIRE(fib_reg(1) == 1);
    REQUIRE(fib_reg(4) == 3);
    REQUIRE(fib_reg(8) == 21);
    REQUIRE(fib_reg(16) == 987);
    REQUIRE(fib_reg(32) == 2178309);
    REQUIRE(fib_reg(64) == 10610209857723);
}
