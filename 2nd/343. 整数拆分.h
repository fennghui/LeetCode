//
// Created by irisfeng on 2023/1/30.
//

#ifndef FH_A01_343_整数拆分_H
#define FH_A01_343_整数拆分_H

#include "../Common.h"

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        /// 可以获得的最大乘积
        vector<int> dp(n + 1, 0);
        dp[2] = 2;
        dp[3] = 3;
        int maxMulti = dp[2];
        for (int i = 4; i <= n; ++i) {
            for (int j = i - 1; j >= 2; --j) {
                dp[i] = max(dp[i], dp[j] * (i - j));
            }
            maxMulti = max(maxMulti, dp[i]);
            //cout << "dp " << i << " " << dp[i] << endl;
        }
        return maxMulti;
    }
};

#endif //FH_A01_343_整数拆分_H
