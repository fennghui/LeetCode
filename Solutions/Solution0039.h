//
// Created by irisfeng on 2022/8/2.
//

#ifndef FH_A01_SOLUTION0039_H
#define FH_A01_SOLUTION0039_H

#include "../Common.h"

//39. 组合总和 mid
//给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates
//中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
//
//candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
//
//对于给定的输入，保证和为 target 的不同组合数少于 150 个。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int curSum;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // 排个序
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }

    void backtracking(vector<int> &candidates, int target, int startIndex) {
        if (curSum == target) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && (curSum + candidates[i] <= target); ++i) {
            curSum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            curSum -= candidates[i];
            path.pop_back();
        }
    }
};

#endif //FH_A01_SOLUTION0039_H
