/******************************************************************************\
|* Write a function `bestSum(targetSum, numbers)` that takes in a `targetSum` *|
|* and an array of numbers as arguments.                                      *|
|*                                                                            *|
|* The function should return an array containing the shortest combination of *|
|* numbers that add up to exactly the target sum.                             *|
|*                                                                            *|
|* If there is a tie for the shortest combination, you may return any one of  *|
|* the shortest.                                                              *|
|* -------------------------------------------------------------------------- *|
|* Problem Source: freecodecamp.org                                           *|
\******************************************************************************/

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
vector<uint64_t> bestSum_dp(uint64_t target, vector<uint64_t> nums, vector<uint64_t> sum) {

    vector<uint64_t> buffer, temp;

    if (target == 0) {
        return sum;
    }

    int sum_size = sum.size();

    for (size_t i = 0; i < nums.size(); i++) {

        if (sum.size() != sum_size){
            sum.pop_back();
        }

        if (target >= nums[i]) {

            sum.push_back(nums[i]);

            if ((temp = bestSum_dp(target - nums[i], nums, sum)).size() > 0) {

                if (buffer.size() == 0 || buffer.size() > temp.size()) {
                    buffer = temp;
                }
            }
        }

    }

    return buffer;
}

vector<uint64_t> bestSum_dp_memo(uint64_t target, vector<uint64_t> nums, bool clear) {

    return {};
}

vector<uint64_t> bestSum_dp_tab(uint64_t target, vector<uint64_t> nums) {

    return {};
}
