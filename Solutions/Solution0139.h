//
// Created by irisfeng on 2022/8/24.
//

#ifndef FH_A01_SOLUTION0139_H
#define FH_A01_SOLUTION0139_H

#include "../Common.h"

//139. 单词拆分
//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
//
//注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) { // 背包
            for (int j = 0; j < i; ++j) { // 物品
                string word = s.substr(j, i - j);
                if(wordSet.find(word) != wordSet.end() && dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

#endif //FH_A01_SOLUTION0139_H
