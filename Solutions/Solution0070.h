//
// Created by irisfeng on 2022/8/19.
//

#ifndef FH_A01_SOLUTION0070_H
#define FH_A01_SOLUTION0070_H

#include "../Common.h"

//70. 爬楼梯 ez
//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> dp(3);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            int sum = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};

#endif //FH_A01_SOLUTION0070_H
