//
// Created by irisfeng on 2023/1/26.
//

#ifndef FH_A01_43_字符串相乘_H
#define FH_A01_43_字符串相乘_H

#include "../Common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int len1 = num1.size(), len2 = num2.size();
        string ans = "0";
        for (int i = len1 - 1; i >= 0; i--) {
            int carry = 0;
            string cur_multi_value;

            /// 补 0
            int zero_num = len1 - 1 - i;
            while (zero_num != 0) {
                cur_multi_value += '0';
                zero_num--;
            }

            for (int j = len2 - 1; j >= 0; j--) {
                int cur_value = carry + (num1[i] - '0') * (num2[j] - '0');
                carry = cur_value / 10;
                cur_multi_value.push_back((char) (cur_value % 10 + '0'));
            }
            if(carry!=0){
                cur_multi_value.push_back((char)(carry + '0'));
            }
            reverse(cur_multi_value.begin(), cur_multi_value.end());

//            cout<<cur_multi_value<<endl;
            ans = add(ans, cur_multi_value);
        }

        return ans;
    }

    string add(string &num1, string &num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int max_len = len1 > len2 ? len1 : len2;
        int num1_zero_num = max_len > len1 ? max_len - len1 : 0;
        int num2_zero_num = max_len > len2 ? max_len - len2 : 0;
        string num1_new, num2_new;
        while (num1_zero_num != 0) {
            num1_new += '0';
            num1_zero_num--;
        }
        num1_new += num1;
        while (num2_zero_num != 0) {
            num2_new += '0';
            num2_zero_num--;
        }
        num2_new += num2;

        int carry = 0;
        string ans;
        for (int i = max_len - 1; i >= 0; i--) {
            int sum = carry + num1_new[i] - '0' + num2_new[i] - '0';
            carry = sum / 10;
            ans.push_back((char) (sum % 10 + '0'));
        }
        if (carry != 0) {
            ans.push_back((char) (carry + '0'));
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //FH_A01_43_字符串相乘_H
