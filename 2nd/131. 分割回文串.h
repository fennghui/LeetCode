//
// Created by irisfeng on 2023/1/30.
//

#ifndef FH_A01_131_分割回文串_H
#define FH_A01_131_分割回文串_H

#include "../Common.h"

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        backTracking(s, 0);
        return res;
    }

    void backTracking(string &s, int curIndex) {
        if (curIndex >= s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = curIndex; i < s.size(); ++i) {
            if (isHuiWen(s, curIndex, i)) {
                path.push_back(s.substr(curIndex, (i - curIndex) + 1));
                backTracking(s, i + 1);
                path.pop_back();
            }
        }
    }

    bool isHuiWen(string &s, int start, int end) {
        while(start <= end){
            if(s[start] == s[end]){
                ++start;
                --end;
            }else{
                return false;
            }
        }
        return true;
    }
};

#endif //FH_A01_131_分割回文串_H
