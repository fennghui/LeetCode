//
// Created by irisfeng on 2023/1/27.
//

#ifndef FH_A01_322_零钱兑换_H
#define FH_A01_322_零钱兑换_H

#include "../Common.h"

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = coins.size() - 1; i >= 0; --i) {
            for (int j = coins[i]; j <= amount; ++j) {
                if (dp[j - coins[i]] != INT32_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return (dp[amount] == INT32_MAX) ? -1 : dp[amount];
    }
};

#endif //FH_A01_322_零钱兑换_H
