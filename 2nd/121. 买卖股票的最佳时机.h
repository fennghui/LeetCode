//
// Created by irisfeng on 2023/2/23.
//

#ifndef FH_A01_121_买卖股票的最佳时机_H
#define FH_A01_121_买卖股票的最佳时机_H

#include "../Common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        int res = 0;
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i){
            profit += prices[i] - prices[i-1];
            if(profit < 0){
                profit = 0;
            }
            res = max(profit, res);
        }
        return res;
    }
};

#endif //FH_A01_121_买卖股票的最佳时机_H
