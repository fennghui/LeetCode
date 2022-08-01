//
// Created by irisfeng on 2022/7/28.
//

#ifndef FH_A01_SOLUTION0077_H
#define FH_A01_SOLUTION0077_H

#include "../Common.h"

//77. 组合 mid
//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
//
//你可以按 任何顺序 返回答案。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }

    void backtracking(int n, int k, int curN) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = curN; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
};

#endif //FH_A01_SOLUTION0077_H
