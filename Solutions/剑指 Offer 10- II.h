//
// Created by hpf on 22-6-26.
//

#ifndef FH_A01_剑指_OFFER_10_II_H
#define FH_A01_剑指_OFFER_10_II_H

#include "../Common.h"

//剑指 Offer 10- II. 青蛙跳台阶问题
//一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
//
//答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

class Solution {
public:
    const int a = 1000000007;

    int numWays(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        vector<int> result(n + 1);
        result[1] = 1;
        result[2] = 2;
        for (int i = 3; i <= n; ++i) {
            result[i] = (result[i - 1] % a + result[i - 2] % a) % a;
        }
        return result[n];
    }
};


#endif //FH_A01_剑指_OFFER_10_II_H
