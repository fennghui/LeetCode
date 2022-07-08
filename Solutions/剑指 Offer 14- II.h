//
// Created by iris on 22-7-8.
//

#ifndef FH_A01_剑指_OFFER_14_II_H
#define FH_A01_剑指_OFFER_14_II_H

#include "../Common.h"

//剑指 Offer 14- II. 剪绳子 II mid
//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。
//请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
//
//答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

/**
 * 动态规划做不了，还是需要使用贪心
 *
 * 大数求余的两种方法：循环取余 快速幂方法
 */
class Solution {
    const int p = 1000000007;
public:
    int cuttingRope(int n) {
        if (n <= 1)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        long rem = 1;
        int b = n % 3, a = n / 3;
        for (int i = 1; i < a; ++i) {
            rem = rem * 3 % p;
        }
        if (b == 1) {
            return rem * 4 % p;
        }
        if (b == 2) {
            return (rem * 3 % p) * 2 % p;
        }

        return rem * 3 % p;
    }
};


#endif //FH_A01_剑指_OFFER_14_II_H
