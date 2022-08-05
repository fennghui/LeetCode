//
// Created by irisfeng on 2022/8/5.
//

#ifndef FH_A01_SOLUTION0122_H
#define FH_A01_SOLUTION0122_H

#include "../Common.h"

//122. 买卖股票的最佳时机 II mid
//给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
//
//在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
//
//返回 你能获得的 最大 利润 。

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        int curDiff;
        for (int i = 1; i < prices.size(); ++i) {
            curDiff = prices[i] - prices[i - 1];
            if (curDiff > 0)
                res += curDiff;
        }
        return res;
    }
};

#endif //FH_A01_SOLUTION0122_H
