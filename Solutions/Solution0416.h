//
// Created by irisfeng on 2022/8/20.
//

#ifndef FH_A01_SOLUTION0416_H
#define FH_A01_SOLUTION0416_H

#include "../Common.h"

//416. 分割等和子集 mid
//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }
        if (sum % 2 == 1) return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for(int i = 0; i < nums.size(); i++){ // 物品遍历
            for(int j = sum; j >= nums[i]; j--){ // 背包遍历
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};

#endif //FH_A01_SOLUTION0416_H
