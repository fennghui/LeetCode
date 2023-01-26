//
// Created by irisfeng on 2023/1/25.
//

#ifndef FH_A01_394_字符串解码_H
#define FH_A01_394_字符串解码_H

#include "../Common.h"

/**
 * 3[a2[c]]
 * 3    2
 * a    cc
 */

class Solution {
public:
    string decodeString(string s) {
        stack<int> digit_stack;
        stack<string> encoded_str_stack;
        int index = 0;

        int k_value = 0;
        string encoded_str;
        while (index < s.size()) {
            if (s[index] >= '0' && s[index] <= '9') { /// 获取字符串重复次数
                k_value = k_value * 10 + s[index] - '0';
            } else if (s[index] == '[') {
                digit_stack.push(k_value);
                encoded_str_stack.push(encoded_str);
                k_value = 0;
                encoded_str = "";
            } else if (s[index] >= 'a' && s[index] <= 'z') {
                encoded_str += s[index];
            } else if (s[index] == ']') {
                int tmp_digit = digit_stack.top();
                digit_stack.pop();
                string tmp_encoded_str = encoded_str_stack.top();
                encoded_str_stack.pop();
                for (int i = 0; i < tmp_digit; i++) {
                    tmp_encoded_str += encoded_str;
                }
                encoded_str = tmp_encoded_str;
            }
            index++;
        }
        return encoded_str;
    }

};

#endif //FH_A01_394_字符串解码_H
