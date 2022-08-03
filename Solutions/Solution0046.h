//
// Created by irisfeng on 2022/8/3.
//

#ifndef FH_A01_SOLUTION0046_H
#define FH_A01_SOLUTION0046_H

#include "../Common.h"

//46. 全排列 mid
//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.empty())
            return res;
        vector<bool> used(nums.size(), false);
        backtracking(nums, 0, used);
        return res;
    }

    void backtracking(vector<int> &nums, int startIndex, vector<bool> used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums, i + 1, used);
                used[i] = false;
                path.pop_back();
            }
        }

    }
};

#endif //FH_A01_SOLUTION0046_H
