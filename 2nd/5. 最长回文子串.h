//
// Created by irisfeng on 2023/1/18.
//

#ifndef FH_A01_5_最长回文子串_H
#define FH_A01_5_最长回文子串_H

#include "../Common.h"

// 回文串有中心
class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") {
            return "";
        }
        string longest;
        int longest_len = 1;
        int longest_str_index = 0;
        int index = 0;
        int str_len = s.size();
        while (index < str_len) {
            // 回文串为奇数
            int left = index - 1;
            int right = index + 1;
            int cur_len = 1;
            while (left >= 0 && right < str_len && s[left] == s[right]) {
                cur_len += 2;
                left--;
                right++;
            }
            if(cur_len > longest_len){
                longest_len = cur_len;
                longest_str_index = left + 1;
            }
            // 回文串为偶数
            int left_1 = index;
            right = index + 1;
            cur_len = 0;
            while (left_1 >= 0 && right < str_len && s[left_1] == s[right]) {
                cur_len += 2;
                left_1--;
                right++;
            }
            if(cur_len > longest_len){
                longest_len = cur_len;
                longest_str_index = left_1 + 1;
            }

            index++;
        }

        return s.substr(longest_str_index, longest_len);
    }
};

#endif //FH_A01_5_最长回文子串_H
