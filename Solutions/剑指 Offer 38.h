//
// Created by irisfeng on 2022/7/12.
//

#ifndef FH_A01_剑指_OFFER_38_H
#define FH_A01_剑指_OFFER_38_H

#include "../Common.h"

//剑指 Offer 38. 字符串的排列 mid
//输入一个字符串，打印出该字符串中字符的所有排列。
//
//你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

class Solution {
public:
    vector<string> result;
    string path = "";
    vector<string> permutation(string s) {
        result.clear();
        path="";
        // 字符串的全排列，回溯
        vector<bool>  used(s.size(), false);
        sort(s.begin(),s.end());
        backtracking(s, used);
        return result;
    }

    void backtracking(string &s, vector<bool> &used){
        if(path.size() == s.size()){
            result.push_back(path);
            return;
        }

        for(int i = 0; i < s.size(); ++i){
            if(i > 0 && s[i] == s[i-1] && used[i-1] == false){
                continue;
            }
            if(used[i] == false){
                used[i] = true;
                path += s[i];
                backtracking(s, used);
                path.erase(path.end() - 1);
                used[i] = false;
            }
        }
    }
};


#endif //FH_A01_剑指_OFFER_38_H
