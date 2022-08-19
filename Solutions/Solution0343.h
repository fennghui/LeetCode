//
// Created by irisfeng on 2022/8/19.
//

#ifndef FH_A01_SOLUTION0343_H
#define FH_A01_SOLUTION0343_H

#include "../Common.h"

//343. 整数拆分 mid
//给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
//
//返回 你可以获得的最大乘积 。

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i - 1; j++) {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }
};

#endif //FH_A01_SOLUTION0343_H
