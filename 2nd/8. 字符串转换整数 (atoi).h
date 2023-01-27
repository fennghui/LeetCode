//
// Created by irisfeng on 2023/1/26.
//

#ifndef FH_A01_8_字符串转换整数_ATOI_H
#define FH_A01_8_字符串转换整数_ATOI_H

#include "../Common.h"

class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int len = s.size();
        /// 前导空格
        while (index < len && s[index] == ' ') {
            ++index;
        }
        if (index >= len) {
            return 0;
        }

        /// 正负号
        bool isMinus = false;
        if (s[index] == '-') {
            isMinus = true;
            ++index;
        } else if (s[index] == '+') {
            ++index;
        }

        long value = 0;
        while (index < len) {
            if (s[index] >= '0' && s[index] <= '9') {
                /// 需要根据正负号不同做截断
                value = value * 10 + s[index];
                long tmp = isMinus ? -value : value;
                if (tmp > INT32_MAX || tmp < INT32_MIN) {
                    value = isMinus ? INT32_MIN : INT32_MAX;
                    return value;
                }
            } else {
                break;
            }
        }
        return isMinus ? -value : value;
    }
};

#endif //FH_A01_8_字符串转换整数_ATOI_H
