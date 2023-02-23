//
// Created by irisfeng on 2023/2/23.
//

#ifndef FH_A01_415_字符串相加_H
#define FH_A01_415_字符串相加_H

#include "../Common.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1index = num1.size() - 1;
        int num2index = num2.size() - 1;
        string res;
        int carry = 0;
        while (num1index >= 0 || num2index >= 0 || carry != 0) {
            int x = num1index >= 0 ? num1[num1index] - '0' : 0;
            int y = num2index >= 0 ? num2[num2index] - '0' : 0;
            int tmpSum = carry + x + y;
            carry = tmpSum / 10;
            res.push_back(tmpSum % 10 + '0');
            --num1index;
            --num2index;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //FH_A01_415_字符串相加_H
