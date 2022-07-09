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
        if (n <= 9)
            return n;
        long cur_multi = 10;
        long cur_value = cur_multi;
        int cur_bit = 2;
        n = n - 9;
        while (n > 0) {
            long num = cur_multi * cur_bit * 9;
            if (n > num) {
                n -= num;
                cur_multi *= 10;
                cur_value = cur_multi;
                cur_bit++;
            } else {
                int a = n / cur_bit;
                int r = n % cur_bit;
                if (r == 0) {
                    return (cur_value + a - 1) % 10;
                } else {
                    string str_ = to_string(cur_value + a);
                    return str_[r-1] - '0';
                }
            }
        }
        return 0;
    }
};


#endif //FH_A01_剑指_OFFER_44_H
