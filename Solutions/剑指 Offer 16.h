//
// Created by irisfeng on 2022/7/16.
//

#ifndef FH_A01_剑指_OFFER_16_H
#define FH_A01_剑指_OFFER_16_H

#include "../Common.h"

//剑指 Offer 16. 数值的整数次方 mid
//实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

//快速幂
class Solution {
public:
    double myPow(double x, int n) {
        long b = n;
        double res = 1.0;
        if (n < 0) {
            b = -b;
            x = 1 / x;
        }
        while (b > 0) {
            if (b & 1)
                res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};


//double myPow(double x, int n) {
//    if (n == 0)
//        return 1;
//
//    double tmp = myPow(x, n / 2);
//    if (n > 0)
//        return (n & 1) ? x * tmp * tmp : tmp * tmp;
//    else
//        return (n & 1) ? (1 / x) * tmp * tmp : tmp * tmp;
//}

#endif //FH_A01_剑指_OFFER_16_H
