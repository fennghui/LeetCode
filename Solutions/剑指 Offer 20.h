//
// Created by irisfeng on 2022/7/14.
//

#ifndef FH_A01_剑指_OFFER_20_H
#define FH_A01_剑指_OFFER_20_H

#include "../Common.h"

//剑指 Offer 20. 表示数值的字符串 mid
//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

class Solution {
public:
    bool isNumber(string s) {
        if (s.length() == 0)
            return false;
        // 去掉空格
        int i = 0;
        while (i < s.length() && s[i] == ' ')
            ++i;

        // 可选的符号
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            ++i;
        }

        // 整数
        bool flag = false;
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            ++i;
            flag = true;
        }

        // 小数点
        if (i < s.length() && s[i] == '.') {
            ++i;
        }

        // 整数
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            flag = true;
            ++i;
        }
        if (!flag)
            return false;

        // 指数
        flag = false;
        if (i < s.length() && (s[i] == 'e' || s[i] == 'E')) {
            ++i;

            // 可选的符号
            if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
                ++i;
            }

            // 整数
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                flag = true;
                ++i;
            }

            if (!flag)
                return false;
        }

        // 空格
        while (i < s.length() && s[i] == ' ')
            ++i;

        return i >= s.length();
    }
};

#endif //FH_A01_剑指_OFFER_20_H
