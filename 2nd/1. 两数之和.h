//
// Created by irisfeng on 2023/2/23.
//

#ifndef FH_A01_1_两数之和_H
#define FH_A01_1_两数之和_H

#include "../Common.h"

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            if (umap.find(target - nums[i]) != umap.end()) {
                int j = umap[target - nums[i]];
                if (j != i) {
                    return {i, j};
                }
            }else{
                umap[nums[i]] = i;
            }
        }
        return {};
    }
};

#endif //FH_A01_1_两数之和_H
