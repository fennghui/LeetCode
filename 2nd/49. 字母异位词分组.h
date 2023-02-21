//
// Created by irisfeng on 2023/2/20.
//

#ifndef FH_A01_49_字母异位词分组_H
#define FH_A01_49_字母异位词分组_H

#include "../Common.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto &str : strs){
            string key = str;
            sort(key.begin(),key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> res;
        for(auto &info : mp){
            res.emplace_back(info.second);
        }
        return res;
    }
};

#endif //FH_A01_49_字母异位词分组_H
