//
// Created by irisfeng on 2022/8/1.
//

#ifndef FH_A01_SOLUTION0017_H
#define FH_A01_SOLUTION0017_H

#include "../Common.h"

//17. 电话号码的字母组合 mid
//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。


class Solution {
public:
    const string letterMap[10] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
    };

    vector<string> res;
    string path;
    string digits_;
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return res;
        digits_ = digits;
        backtracking(0);
        return res;
    }

    void backtracking(int cur) {
        if(cur >= digits_.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < letterMap[digits_[cur]-'0'].size(); ++i){
            path.push_back(letterMap[digits_[cur]-'0'][i]);
            backtracking(cur + 1);
            path.pop_back();
        }
    }
};

#endif //FH_A01_SOLUTION0017_H
