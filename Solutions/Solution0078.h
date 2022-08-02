//
// Created by irisfeng on 2022/8/2.
//

#ifndef FH_A01_SOLUTION0078_H
#define FH_A01_SOLUTION0078_H

#include "../Common.h"

//78. 子集 mid
//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsets(vector<int> &nums) {
        backtracking(nums, 0);
        return res;
    }

    void backtracking(vector<int> &nums, int startIndex) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};

#endif //FH_A01_SOLUTION0078_H
