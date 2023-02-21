//
// Created by irisfeng on 2023/2/21.
//

#ifndef FH_A01_213_打家劫舍_II_H
#define FH_A01_213_打家劫舍_II_H

#include "../Common.h"

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n, 0); /// dp[i] 指到第 i 家最多能偷到的钱财数

        /// 0 ~ n-1
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < n - 1; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int max1 = dp[n-2];

        /// 1 ~ n
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int max2 = dp[n-1];

        return max(max1, max2);
    }
};

#endif //FH_A01_213_打家劫舍_II_H
