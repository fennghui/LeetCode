//
// Created by irisfeng on 2022/8/19.
//

#ifndef FH_A01_SOLUTION0746_H
#define FH_A01_SOLUTION0746_H

#include "../Common.h"

//746. 使用最小花费爬楼梯 ez
//给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
//
//你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
//
//请你计算并返回达到楼梯顶部的最低花费。

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        int dp0 = cost[0];
        int dp1 = cost[1];
        for (int i = 2; i < n; i++) {
            int dpi = min(dp0, dp1) + cost[i];
            dp0 = dp1;
            dp1 = dpi;
        }
        return min(dp0, dp1);
    }
};

#endif //FH_A01_SOLUTION0746_H
