//
// Created by iris on 22-7-8.
//

#ifndef FH_A01_剑指_OFFER_60_H
#define FH_A01_剑指_OFFER_60_H

#include "../Common.h"

//剑指 Offer 60. n个骰子的点数 mid 动态规划
//把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
//
//你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0 / 6);
        for (int i = 2; i <= n; ++i) {
            vector<double> tmp(i * 6 - i + 1, 0);
            for (int j = 0; j < dp.size(); ++j) {
                for (int k = 0; k < 6; ++k) {
                    tmp[j + k] += dp[j]/ 6;
                }
            }
            dp = tmp;
        }
        return dp;
    }
};

#endif //FH_A01_剑指_OFFER_60_H
