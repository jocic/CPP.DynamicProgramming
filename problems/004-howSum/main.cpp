/********************************************************************************\
|* Write a function `howSum(targetSum, numbers)` that takes in a `targetSum`    *|
|* and an array of numbers as arguments. The function should return an array    *|
|* containing any combination of elements that add up to exactly the targetSum. *|
|*                                                                              *|
|* If there is no combination that adds up to the targetSum, then return an     *|
|* empty array of elements.                                                     *|
|*                                                                              *|
|* If there are multiple combinations possible, you may return any single one.  *|
|* ---------------------------------------------------------------------------- *|
|* Problem Source: freecodecamp.org                                             *|
\********************************************************************************/

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
 * @param vector<uint64_t> sum
 *   Variable used by the DP algorithm - should be left as is.
 * @return vector<uint64_t>
 *   Array of numbers  which sum is equal to the provided target. Empty
 *   array will be provided there is no possible solution.
 */
vector<uint64_t> how_sum_dp(uint64_t target, vector<uint64_t> nums, vector<uint64_t> sum) {

    vector<uint64_t> results;

    if (target == 0) {
        return sum;
    }

    int sum_size = sum.size();

    for (size_t i = 0; i < nums.size(); i++) {

        if (target >= nums[i]) {

            if (sum.size() > sum_size) {
                sum.pop_back();
            }

            sum.push_back(nums[i]);

            if ((results = how_sum_dp(target - nums[i], nums, sum)).size() > 0) {
                return results;
            }
        }
    }

    return {};
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
 *   Flag used for clearing memoization map.
 * @return vector<uint64_t>
 *   Array of numbers  which sum is equal to the provided target. Empty
 *   array will be provided there is no possible solution.
 */
vector<uint64_t> how_sum_dp_memo(uint64_t target, vector<uint64_t> nums, bool clear) {

    static map<uint64_t, vector<uint64_t>> memo;
    static vector<uint64_t> sum;

    vector<uint64_t> results;

    if (clear) {
        memo.clear();
        sum.clear();
    }

    auto search = memo.find(target);

    if (search != memo.end()) {
        return search->second;

    }

    if (target == 0) {
        memo.insert({ target, sum });
        return sum;
    }

    int sum_size = sum.size();

    for (size_t i = 0; i < nums.size(); i++) {

        if (target >= nums[i]) {

            if (sum.size() > sum_size) {
                sum.pop_back();
            }

            sum.push_back(nums[i]);

            if ((results = how_sum_dp_memo(target - nums[i], nums, false)).size() > 0) {
                return results;
            }
        }
    }

    return {};
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
 * @return vector<uint64_t>
 *   Array of numbers  which sum is equal to the provided target. Empty
 *   array will be provided there is no possible solution.
 */
vector<uint64_t> how_sum_dp_tab(uint64_t target, vector<uint64_t> nums) {

    size_t tab_len = target + 1;

    vector<uint64_t>* tab = new vector<uint64_t>[tab_len];

    size_t i, j;

    uint64_t curr_num, next_num;

    // Seed Tab

    for (i = 0; i < nums.size(); i++) {

        curr_num = nums[i];

        tab[curr_num].push_back(curr_num);
    }

    // Process Tab

    for (i = 0; i < tab_len; i++) {

        if (tab[i].size() > 0) {

            for (j = 0; j < nums.size(); j++) {

                curr_num = nums[j];
                next_num = i + curr_num;

                if (next_num < tab_len && tab[next_num].empty()) {
                    tab[next_num] = tab[i];
                    tab[next_num].push_back(curr_num);
                }

                if (next_num == target) {
                    break;
                }
            }
        }
    }

    return tab[target];
}
