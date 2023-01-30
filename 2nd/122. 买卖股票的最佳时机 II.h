//
// Created by irisfeng on 2023/1/30.
//

#ifndef FH_A01_122_买卖股票的最佳时机_II_H
#define FH_A01_122_买卖股票的最佳时机_II_H

#include "../Common.h"

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> dp(n, 0); /// 买卖股票可以最多挣的钱
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] > prices[i - 1]) {
                dp[i] = dp[i - 1] + prices[i] - prices[i - 1];
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};

#endif //FH_A01_122_买卖股票的最佳时机_II_H
