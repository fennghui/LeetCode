//
// Created by irisfeng on 2022/8/1.
//

#ifndef FH_A01_SOLUTION0216_H
#define FH_A01_SOLUTION0216_H

#include "../Common.h"

//216. 组合总和 III mid
//找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
//
//只使用数字1到9
//每个数字 最多使用一次
//返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum;

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return res;
    }

    void backtracking(int k, int n, int startIndex) {
        if (path.size() == k) {
            if (sum == n) {
                res.push_back(path);
            }
            return;
        }

        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; ++i) {
            if (sum + i <= n) {
                path.push_back(i);
                sum += i;
                backtracking(k, n, i + 1);
                path.pop_back();
                sum -= i;
            }
        }
    }
};

#endif //FH_A01_SOLUTION0216_H
