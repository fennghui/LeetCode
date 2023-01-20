//
// Created by irisfeng on 2023/1/20.
//

#ifndef FH_A01_17_电话号码的字母组合_H
#define FH_A01_17_电话号码的字母组合_H

#include "../Common.h"

class Solution {
public:
    string digit_letter_map[10] = {
            {""},
            {""},
            {"abc"},
            {"def"},
            {"ghi"},
            {"jkl"},
            {"mno"},
            {"pqrs"},
            {"tuv"},
            {"wxyz"}
    };

    vector<string> res;
    string path;

    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return res;
        }
        backTracing(digits, digits.size(),0);
        return res;
    }

    void backTracing(string &digits, int length, int index) {
        if (path.size() == length) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < digit_letter_map[digits[index] - '0'].size(); i++) {
            path.push_back(digit_letter_map[digits[index] - '0'][i]);
            backTracing(digits, length, index + 1);
            path.pop_back();
        }
    }
};

#endif //FH_A01_17_电话号码的字母组合_H
