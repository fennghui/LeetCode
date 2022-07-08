//
// Created by iris on 22-7-8.
//

#ifndef FH_A01_剑指_OFFER_49_H
#define FH_A01_剑指_OFFER_49_H

#include "../Common.h"

//剑指 Offer 49. 丑数 mid 动态规划
//我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
        if (n == 1)
            return 1;
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
            if (dp[i] == dp[p2] * 2)
                ++p2;
            if (dp[i] == dp[p3] * 3)
                ++p3;
            if (dp[i] == dp[p5] * 5)
                ++p5;
        }
        return dp[n];
    }
};

#endif //FH_A01_剑指_OFFER_49_H
