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
 * @param bool clear = true
 *   Flag used for clearing summation vector.
 * @return vector<uint64_t>
 *   Array of numbers  which sum is equal to the provided target. Empty
 *   array will be provided there is no possible solution.
 */
vector<uint64_t> how_sum_dp(uint64_t target, vector<uint64_t> nums, bool clear) {

    vector<uint64_t> results;

    static vector<uint64_t> sum;

    if (target == 0) {
        return sum;
    }

    if (clear) {
        sum.clear();
    }

    int sum_size = sum.size();

    for (uint64_t i = 0; i < nums.size(); i++) {

        if (target >= nums[i]) {

            if (sum.size() > sum_size) {
                sum.pop_back();
            }

            sum.push_back(nums[i]);

            if ((results = how_sum_dp(target - nums[i], nums, false)).size() > 0) {
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

    for (uint64_t i = 0; i < nums.size(); i++) {

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

    int i, j, k;
    int base, number, multiple, probe;

    uint64_t min = UINT64_MAX;

    // Initialize Tab

    for (i = 0; i < nums.size(); i++) {

        base = nums[i];

        if (base < min) {
            min = base;
        }

        for (number = base, multiple = 1; number <= target; multiple++, number = base * multiple) {

            if (tab[number].size() > 0) {
                continue;
            }

            for (j = 0; j < multiple; j++) {
                tab[number].push_back(base);
            }
        }
    }

    // Populate Gaps

    for (i = 0; i < tab_len; i++) {

        if (tab[i].size() == 0) {

            for (j = 0; j < nums.size(); j++) {

                probe = i - nums[j];

                if (probe < 0) {
                    continue;
                }

                if (tab[probe].size() > 0 && (nums[j] + probe) == target) {

                    tab[i].push_back(nums[j]);

                    for (k = 0; k < tab[probe].size(); k++) {
                        tab[i].push_back(tab[probe][k]);
                    }
                }
            }
        }
    }

    return tab[target];
}
