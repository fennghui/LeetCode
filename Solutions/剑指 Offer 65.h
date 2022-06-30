//
// Created by hpf on 22-6-30.
//

#ifndef FH_A01_剑指_OFFER_65_H
#define FH_A01_剑指_OFFER_65_H

#include "../Common.h"

//剑指 Offer 65. 不用加减乘除做加法 ez
//写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

/**
 * 有点难的
 */
class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int c = (unsigned int) (a & b) << 1;
            a ^= b;
            b = c;
        }
        return a;
    }
};

#endif //FH_A01_剑指_OFFER_65_H
