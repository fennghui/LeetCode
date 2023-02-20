//
// Created by irisfeng on 2023/2/20.
//

#ifndef FH_A01_139_单词拆分_H
#define FH_A01_139_单词拆分_H

#include "../Common.h"

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) { /// 背包
            for (int j = 0; j <= i; ++j) { /// 物品
                string temp = s.substr(j, i-j);
                if(wordDictSet.find(temp) != wordDictSet.end() && dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

#endif //FH_A01_139_单词拆分_H
