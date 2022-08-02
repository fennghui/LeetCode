//
// Created by irisfeng on 2022/8/2.
//

#ifndef FH_A01_SOLUTION0040_H
#define FH_A01_SOLUTION0040_H

#include "../Common.h"

//40. 组合总和 II mid
//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的每个数字在每个组合中只能使用 一次 。
//
//注意：解集不能包含重复的组合。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int curSum;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
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
            if (i > 0 && candidates[i] == candidates[i - 1] && i != startIndex) {
                continue;
            }
            curSum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i + 1);
            path.pop_back();
            curSum -= candidates[i];
        }
    }
};

#endif //FH_A01_SOLUTION0040_H
