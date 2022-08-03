//
// Created by irisfeng on 2022/8/3.
//

#ifndef FH_A01_SOLUTION0090_H
#define FH_A01_SOLUTION0090_H

#include "../Common.h"

//90. 子集 II mid
//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
//
//解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, 0, used);
        return res;
    }

    void backtracking(vector<int> &nums, int startIndex, vector<bool> used) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i-1])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
};

#endif //FH_A01_SOLUTION0090_H
