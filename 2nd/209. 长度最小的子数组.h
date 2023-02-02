//
// Created by irisfeng on 2023/2/2.
//

#ifndef FH_A01_209_长度最小的子数组_H
#define FH_A01_209_长度最小的子数组_H

#include "../Common.h"

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int res = nums.size() + 1;
        int left = 0;
        int right = 0;
        int curSum = 0;
        while (right < nums.size()) {
            curSum += nums[right];
            ++right;
            if (curSum >= target) {
                while (curSum - nums[left] >= target) {
                    curSum -= nums[left];
                    ++left;
                }
                res = min(res, right - left);
            }
        }

        if(res == nums.size() + 1){
            return 0;
        }
        return res;
    }
};

#endif //FH_A01_209_长度最小的子数组_H
