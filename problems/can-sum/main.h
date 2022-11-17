#ifndef CAN_SUM_H

#define CAN_SUM_H

#include <iostream>
#include <map>
#include <vector>
#include <vcruntime.h>

using namespace std;

bool canSum_dp(int target, vector<int> nums);
bool canSum_dp_memo(int target, vector<int> nums, bool clear = true);
bool canSum_dp_tab(int target, vector<int> nums);

#endif
