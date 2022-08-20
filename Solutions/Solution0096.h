//
// Created by irisfeng on 2022/8/19.
//

#ifndef FH_A01_SOLUTION0096_H
#define FH_A01_SOLUTION0096_H

#include "../Common.h"

//96. 不同的二叉搜索树 mid
//给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int sum = 0;
            for(int j = 0; j < i ; j++){
                sum += dp[j] * dp[i-j-1];
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};

#endif //FH_A01_SOLUTION0096_H
