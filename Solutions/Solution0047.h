//
// Created by irisfeng on 2022/8/3.
//

#ifndef FH_A01_SOLUTION0047_H
#define FH_A01_SOLUTION0047_H

#include "../Common.h"

//47. 全排列 II mid
//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        //sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }

    void backtracking(vector<int> &nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        int isUsed[21] = {0};
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] || isUsed[nums[i] + 10] == 1)
                continue;
            isUsed[nums[i] + 10] = 1;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
};

#endif //FH_A01_SOLUTION0047_H
