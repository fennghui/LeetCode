//
// Created by irisfeng on 2022/8/8.
//

#ifndef FH_A01_SOLUTION0714_H
#define FH_A01_SOLUTION0714_H

#include "../Common.h"

//714. 买卖股票的最佳时机含手续费 mid
//给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
//
//你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
//
//返回获得利润的最大值。
//
//注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()==0) return 0;
        int buy = prices[0] + fee;
        int res = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] + fee < buy){
                buy = prices[i] + fee;
            }else if(prices[i] > buy){
                res += prices[i] - buy;
                buy = prices[i];
            }
        }
        return res;
    }
};

#endif //FH_A01_SOLUTION0714_H
