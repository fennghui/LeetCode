//
// Created by irisfeng on 2022/8/21.
//

#ifndef FH_A01_SOLUTION0474_H
#define FH_A01_SOLUTION0474_H

#include "../Common.h"

//474. 一和零 mid
//给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
//
//请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
//
//如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); ++i) {
            int zero_num = 0;
            int one_num = 0;
            for (auto c: strs[i]) {
                if (c == '0') ++zero_num;
                if (c == '1') ++one_num;
            }
            for (int j = m; j >= zero_num; --j) {
                for (int k = n; k >= one_num; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - zero_num][k - one_num] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

#endif //FH_A01_SOLUTION0474_H
