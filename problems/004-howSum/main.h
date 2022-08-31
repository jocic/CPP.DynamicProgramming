#ifndef MAIN_004_H

#define MAIN_004_H

#include <iostream>
#include <map>
#include <vector>
#include <cstdint>
#include <vcruntime.h>

using namespace std;

vector<uint64_t> how_sum_dp(uint64_t target, vector<uint64_t> nums, vector<uint64_t> sum = {});
vector<uint64_t> how_sum_dp_memo(uint64_t target, vector<uint64_t> nums, bool clear = true);
vector<uint64_t> how_sum_dp_tab(uint64_t target, vector<uint64_t> nums);

#endif
