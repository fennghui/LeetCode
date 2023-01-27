//
// Created by irisfeng on 2023/1/27.
//

#ifndef FH_A01_39_组合总和_H
#define FH_A01_39_组合总和_H

#include "../Common.h"

/**
 * 回溯
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0);
        return res;
    }

    void backTracking(vector<int> &candidates, int target, int start) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                target -= candidates[i];
                path.push_back(candidates[i]);
                backTracking(candidates, target, i);
                target += candidates[i];
                path.pop_back();
            }
        }
    }
};

#endif //FH_A01_39_组合总和_H
