//
// Created by iris on 22-7-8.
//

#ifndef FH_A01_剑指_OFFER_46_H
#define FH_A01_剑指_OFFER_46_H

#include "../Common.h"

//剑指 Offer 46. 把数字翻译成字符串 mid 动态规划
//给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
//一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

class Solution {
public:
    int translateNum(int num) {
        // 1. 确定 dp 数组以及下标的含义
        // 2. 确定递推公式
        // 3. dp 数组初始化
        // 4. 确定遍历顺序
        // 5. 推导 dp 数组
        string str = to_string(num);
        vector<int> dp(str.size(), 0);
        if (str.size() == 1)
            return 1;
        dp[0] = 1;
        int value = stoi(str.substr(0, 2));
        if (value >= 10 && value <= 25)
            dp[1] = 2;
        else
            dp[1] = 1;

        for (int i = 2; i < str.size(); ++i) {
            int tmp = stoi(str.substr(i - 1, 2));
            if (tmp >= 10 && tmp <= 25)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i-1];
        }
        return dp[str.size() - 1];

    }
};

#endif //FH_A01_剑指_OFFER_46_H
