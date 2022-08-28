#ifndef MAIN_003_H

#define MAIN_003_H

#include <iostream>
#include <map>
#include <cstdint>

using namespace std;

bool canSum_dp(uint64_t target, uint64_t* nums, size_t nums_len);
bool canSum_dp_memo(uint64_t target, uint64_t* nums, size_t nums_len, bool clear = true);
bool canSum_dp_tab(uint64_t target, uint64_t* nums, size_t nums_len);

#endif
