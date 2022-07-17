//
// Created by irisfeng on 2022/7/16.
//

#ifndef FH_A01_剑指_OFFER_19_H
#define FH_A01_剑指_OFFER_19_H

#include "../Common.h"

//剑指 Offer 19. 正则表达式匹配 hard
//请实现一个函数用来匹配包含'.'和'*'的正则表达式。
//模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
//在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，
//但与"aa.a"和"ab*a"均不匹配。

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, false));

        // 初始化
        dp[0][0] = true;
        for (int i = 2; i <= p_len; ++i) {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        }
        for (int i = 1; i <= s_len; ++i) {
            for (int j = 1; j <= p_len; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i - 1][j]; // 包含1次
                    }
                    dp[i][j] = dp[i][j] || dp[i][j - 2]; // 包含0次
                }
            }
        }
        return dp[s_len][p_len];
    }
};

#endif //FH_A01_剑指_OFFER_19_H
