//
// Created by irisfeng on 2022/8/19.
//

#ifndef FH_A01_SOLUTION0509_H
#define FH_A01_SOLUTION0509_H

#include "../Common.h"

//509. 斐波那契数 ez
//斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

#endif //FH_A01_SOLUTION0509_H
