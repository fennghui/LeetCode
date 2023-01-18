//
// Created by irisfeng on 2023/1/18.
//

#ifndef FH_A01_7_整数反转_H
#define FH_A01_7_整数反转_H

#include "../Common.h"

/// 假设环境不允许存储 64 位整数（有符号或无符号）。

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int curr_bit = x % 10;
            /**
             * 因为x本身会被int限制，当x为正数并且位数和Integer.MAX_VALUE的位数相等时首位最大只能为2，
             * 所以逆转后不会出现res = Integer.MAX_VALUE / 10 && tmp > 2的情况，自然也不需要判断
             * res==214748364 && tmp>7了，反之负数情况也一样
             *
             * 而且这个判断是在更新 res 前进行
             */
            if (res > INT32_MAX / 10 || res < INT32_MIN / 10) {
                return 0;
            }
            x = x / 10;
            res = res * 10 + curr_bit;

        }
        return res;
    }
};

#endif //FH_A01_7_整数反转_H
