//
// Created by iris on 22-7-9.
//

#ifndef FH_A01_剑指_OFFER_63_H
#define FH_A01_剑指_OFFER_63_H

#include "../Common.h"

//剑指 Offer 63. 股票的最大利润 mid 动态规划
//假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        if( n == 2)
            return max(prices[1] - prices[0], 0);
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = max(prices[1] - prices[0], 0);
        int maxValue = dp[1];
        for (int i = 2; i < n; ++i) {
            if(prices[i] > prices[i-1]){
                dp[i] = dp[i-1] + prices[i] - prices[i-1];
            }else{
                dp[i] = max(dp[i-1] - (prices[i-1] - prices[i]), 0);
            }
            if(dp[i] > maxValue)
                maxValue = dp[i];
        }
        return maxValue;
    }
};

#endif //FH_A01_剑指_OFFER_63_H
