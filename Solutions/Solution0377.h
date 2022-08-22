//
// Created by irisfeng on 2022/8/22.
//

#ifndef FH_A01_SOLUTION0377_H
#define FH_A01_SOLUTION0377_H

#include "../Common.h"

//377. 组合总和 Ⅳ mid
//给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
//
//题目数据保证答案符合 32 位整数范围。

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i <= target; ++i){
            for(int j = 0; j < nums.size(); ++j){
                if(i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]])
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};

#endif //FH_A01_SOLUTION0377_H
