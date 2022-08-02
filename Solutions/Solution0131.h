//
// Created by irisfeng on 2022/8/2.
//

#ifndef FH_A01_SOLUTION0131_H
#define FH_A01_SOLUTION0131_H

#include "../Common.h"

//131. 分割回文串 mid
//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
//
//回文串 是正着读和反着读都一样的字符串。

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        if(s.empty()){
            return res;
        }
        backtracking(s,0);
        return res;
    }

    void backtracking(string &s, int startIndex) {
        if (startIndex >= s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); ++i) {
            int left = startIndex;
            int right = i;
            bool flag = true;
            while (right > left) {
                if (s[left] == s[right]) {
                    ++left;
                    --right;
                }else{
                    flag = false;
                    break;
                }
            }
            if(!flag)
                continue;

            string cur = s.substr(startIndex, i - startIndex + 1);
            path.push_back(cur);
            backtracking(s,i+1);
            path.pop_back();
        }
    }
};

#endif //FH_A01_SOLUTION0131_H
