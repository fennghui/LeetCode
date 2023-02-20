//
// Created by irisfeng on 2023/2/19.
//

#ifndef FH_A01_剑指_OFFER_49_丑数_H
#define FH_A01_剑指_OFFER_49_丑数_H

#include "../Common.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
            if (dp[i] == dp[p2] * 2) ++p2;
            if (dp[i] == dp[p3] * 3) ++p3;
            if (dp[i] == dp[p5] * 5) ++p5;
        }
        return dp[n];
    }
};

#endif //FH_A01_剑指_OFFER_49_丑数_H
