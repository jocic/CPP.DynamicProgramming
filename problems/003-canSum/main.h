#ifndef MAIN_003_H

#define MAIN_003_H

#include <iostream>
#include <map>
#include <vector>
#include <cstdint>

using namespace std;

bool canSum_dp(uint64_t target, vector<uint64_t> nums);
bool canSum_dp_memo(uint64_t target, vector<uint64_t> nums, bool clear = true);
bool canSum_dp_tab(uint64_t target, vector<uint64_t> nums);

#endif
