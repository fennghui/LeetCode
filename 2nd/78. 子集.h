//
// Created by irisfeng on 2023/2/2.
//

#ifndef FH_A01_78_子集_H
#define FH_A01_78_子集_H

#include "../Common.h"

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsets(vector<int> &nums) {
        backTracking(nums, 0);
        return res;
    }

    void backTracking(vector<int> &nums, int startIndex) {
        res.emplace_back(path);
        for (int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
};

#endif //FH_A01_78_子集_H
