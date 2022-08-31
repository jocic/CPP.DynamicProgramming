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
 * @param vector<uint64_t> nums
 *   Array of numbers that should be checked.
 * @return bool
 *   Value `TRUE` if target sum can be formed with the
 *   provided array of numbers, and vice versa.
 */
bool canSum_dp(uint64_t target, vector<uint64_t> nums) {

    if (target == 0) {
        return true;
    }

    for (size_t i = 0; i < nums.size(); i++) {

        if (target >= nums[i] && canSum_dp(target - nums[i], nums)) {
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
 * @param vector<uint64_t> nums
 *   Array of numbers that should be checked.
 * @param bool clear = true
 *   Flag used to clear memoization map.
 * @return bool
 *   Value `TRUE` if target sum can be formed with the
 *   provided array of numbers, and vice versa.
 */
bool canSum_dp_memo(uint64_t target, vector<uint64_t> nums, bool clear) {

    static map<uint64_t, bool> memo;

    uint64_t new_target;
    bool     result;

    if (clear) {
        memo.clear();
    }

    auto search = memo.find(target);

    if (search != memo.end()) {
        return search->second;
    }

    if (target == 0) {
        return true;
    }

    for (size_t i = 0; i < nums.size(); i++) {

        if (target >= nums[i]) {

            new_target = target - nums[i];
            result     = canSum_dp_memo(new_target, nums, false);

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
 * @param vector<uint64_t> nums
 *   Array of numbers that should be checked.
 * @return bool
 *   Value `TRUE` if target sum can be formed with the
 *   provided array of numbers, and vice versa.
 */
bool canSum_dp_tab(uint64_t target, vector<uint64_t> nums) {

    uint64_t step = UINT64_MAX;

    size_t i, j;

    uint64_t next_num;

    size_t tab_len = target + 1;
    bool*  tab     = new bool[tab_len];

    // Initialize Tab

    fill(&tab[0], &tab[tab_len], false);

    tab[0] = true;

    for (i = 0; i < tab_len; i++) {

        for (j = 0; tab[i] && j < nums.size(); j++) {

            if ((next_num = i + nums[j]) < tab_len) {
                tab[next_num] = true;
            }
        }
    }

    return tab[target];
}
