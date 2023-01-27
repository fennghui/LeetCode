//
// Created by irisfeng on 2023/1/27.
//

#ifndef FH_A01_279_完全平方数_H
#define FH_A01_279_完全平方数_H

#include "../Common.h"

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) { /// 外层遍历物品
            for (int j = i * i; j <= n; j++) { /// 内层遍历背包
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};

#endif //FH_A01_279_完全平方数_H
