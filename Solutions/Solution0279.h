//
// Created by irisfeng on 2022/8/24.
//

#ifndef FH_A01_SOLUTION0279_H
#define FH_A01_SOLUTION0279_H

#include "../Common.h"

//279. 完全平方数 mid
//给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
//
//完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; ++i) {
            for (int j = i * i; j <= n; ++j) {
                if (dp[j - i * i] != INT32_MAX)
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};

#endif //FH_A01_SOLUTION0279_H
