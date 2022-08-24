//
// Created by irisfeng on 2022/8/22.
//

#ifndef FH_A01_SOLUTION0322_H
#define FH_A01_SOLUTION0322_H

#include "../Common.h"

//322. 零钱兑换 mid
//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//
//计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
//
//你可以认为每种硬币的数量是无限的。

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = coins.size() - 1; i >= 0; --i){
            for(int j = coins[i]; j <= amount; ++j){
                if(dp[j - coins[i]] != INT32_MAX){
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if(dp[amount] == INT32_MAX) return -1;
        return dp[amount];
    }
};

#endif //FH_A01_SOLUTION0322_H
