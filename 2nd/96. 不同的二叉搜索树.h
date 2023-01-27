//
// Created by irisfeng on 2023/1/27.
//

#ifndef FH_A01_96_不同的二叉搜索树_H
#define FH_A01_96_不同的二叉搜索树_H

#include "../Common.h"

class Solution {
public:
    int numTrees(int n) {
        if (n == 1 || n == 2) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};

#endif //FH_A01_96_不同的二叉搜索树_H
