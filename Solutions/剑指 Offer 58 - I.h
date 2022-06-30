//
// Created by hpf on 22-6-30.
//

#ifndef FH_A01_剑指_OFFER_58_I_H
#define FH_A01_剑指_OFFER_58_I_H

#include "../Common.h"

//剑指 Offer 58 - I. 翻转单词顺序 ez
//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
//例如输入字符串" I am a student. "，则输出"student. a am I"。

class Solution {
public:
    string reverseWords(string s) {
        // 1. 去除多余空格
        vector<string> words;
        string result;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            while (right < s.size() && s[right] == ' ') {
                ++right;
            }
            left = right;
            while (right < s.size() && s[right] != ' ') {
                ++right;
            }
            if (left != right)
                words.push_back(s.substr(left, right - left));
        }
        // 2.
        for (int i = words.size() - 1; i >= 0; --i) {
            result += words[i];
            if (i != 0) {
                result += " ";
            }
        }
        return result;
    }
};

#endif //FH_A01_剑指_OFFER_58_I_H
