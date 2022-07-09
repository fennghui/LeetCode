//
// Created by iris on 22-7-9.
//

#ifndef FH_A01_剑指_OFFER_44_H
#define FH_A01_剑指_OFFER_44_H

#include "../Common.h"

//剑指 Offer 44. 数字序列中某一位的数字 mid
//数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
//
//请写一个函数，求任意第n位对应的数字。

class Solution {
public:
    int findNthDigit(int n) {
        long cur_value = 1;
        int cur_bit = 1;
        long cnt = cur_value * cur_bit * 9;
        while (n > cnt) {
            n -= cnt;
            cur_value *= 10;
            cur_bit++;
            cnt = cur_value * cur_bit * 9;
        }
        n--;
        long a = n / cur_bit;
        long r = n % cur_bit;
        return to_string(cur_value + a)[r] - '0';
    }
};


#endif //FH_A01_剑指_OFFER_44_H
