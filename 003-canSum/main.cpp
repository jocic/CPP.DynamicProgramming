/**********************************************************************\
|* Write a function `canSum(targetSum, numbers)` that takes in        *|
|* a targetSum and an array of numbers as arguments. The function     *|
|* should return a boolean indicating whether or not it is            *|
|* possible to generate the `targetSum` using numbers from the array. *|
|*                                                                    *|
|* You may use an element of the array as many times as needed.       *|
|*                                                                    *|
|* You may assume that all input numbers are non-negative.            *|
|* ------------------------------------------------------------------ *|
|* Problem Source: freecodecamp.org                                   *|
\**********************************************************************/

#include "main.h"

/**
 * Generic Dynamic Programming implementation.
 *
 * @author    Djordje Jocic <office@djordjejocic.com>
 * @copyright 2022 All Rights Reserved
 * @version   1.0.0
 *
 * @param uint64_t target
 *   Target sum that is being searched for.
 * @param uint64_t* nums
 *   Array of numbers that should be checked.
 * @param uint64_t nums_len
 *   Length of the provided array.
 * @return bool
 *   Value `TRUE` if target sum can be formed with the
 *   provided array of numbers, and vice versa.
 */
bool canSum_dp(uint64_t target, uint64_t* nums, size_t nums_len) {

    if (target == 0) {
        return true;
    }

    for (int i = 0; i < nums_len; i++) {

        if (target >= nums[i] && canSum_dp(target - nums[i], nums, nums_len)) {
            return true;
        }
    }

    return false;
}

/**
 * DP implementation optimized with the Memoization pattern.
 *
 * @author    Djordje Jocic <office@djordjejocic.com>
 * @copyright 2022 All Rights Reserved
 * @version   1.0.0
 *
 * @param uint64_t target
 *   Target sum that is being searched for.
 * @param uint64_t* nums
 *   Array of numbers that should be checked.
 * @param uint64_t nums_len
 *   Length of the provided array.
 * @return bool
 *   Value `TRUE` if target sum can be formed with the
 *   provided array of numbers, and vice versa.
 */
bool canSum_dp_memo(uint64_t target, uint64_t* nums, size_t nums_len, bool clear) {

    static map<uint64_t, bool> memo;

    uint64_t new_target;
    bool     result;

    auto search = memo.find(target);

    if (clear) {
        memo.clear();
    }

    if (search != memo.end()) {
        return search->second;
    }

    if (target == 0) {
        return true;
    }

    for (int i = 0; i < nums_len; i++) {

        if (target >= nums[i]) {

            new_target = target - nums[i];
            result     = canSum_dp_memo(new_target, nums, nums_len, false);

            memo.insert({ new_target, result });

            if (result) {
                return true;
            }
        }
    }

    return false;
}

/**
 * DP implementation optimized with the Tabulation pattern.
 *
 * @author    Djordje Jocic <office@djordjejocic.com>
 * @copyright 2022 All Rights Reserved
 * @version   1.0.0
 *
 * @param uint64_t target
 *   Target sum that is being searched for.
 * @param uint64_t* nums
 *   Array of numbers that should be checked.
 * @param uint64_t nums_len
 *   Length of the provided array.
 * @return bool
 *   Value `TRUE` if target sum can be formed with the
 *   provided array of numbers, and vice versa.
 */
bool canSum_dp_tab(uint64_t target, uint64_t* nums, size_t nums_len) {

    uint64_t step = UINT64_MAX;

    int i, j, k;

    int   tab_len = target + 1;
    bool* tab     = new bool[tab_len];

    // Initialize Tab

    fill(&tab[0], &tab[target], false);

    for (i = 0, k = nums[0]; i < nums_len; i++, k = nums[i]) {

        if (k < step) {
            step = k;
        }

        tab[k] = true;
    }

    // Shift Values

    for (i = step * 2; i < tab_len; i += step) {

        for (j = i; j < i + step; j++) {
            tab[j] = tab[j - step];
        }
    }

    return tab[target];
}
