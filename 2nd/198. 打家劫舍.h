//
// Created by irisfeng on 2023/1/28.
//

#ifndef FH_A01_198_打家劫舍_H
#define FH_A01_198_打家劫舍_H

#include "../Common.h"

/**
 * 1,0,3,12,0,8
 */

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n + 1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
};

#endif //FH_A01_198_打家劫舍_H
