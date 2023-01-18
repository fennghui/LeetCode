//
// Created by irisfeng on 2023/1/18.
//

#ifndef FH_A01_15_三数之和_H
#define FH_A01_15_三数之和_H

#include "../Common.h"

// 排序 + 双指针
class Solution {
public:
    // -4  0  2 2  2 3
    // -4 -1 -1 0  3 3
    // -4 -4 -1 0  1 3
    vector<vector<int>> threeSum(vector<int> &nums) {
        int size = nums.size();
        if (size < 3) {
            return {};
        }
        vector<vector<int>> res;
        vector<int> tmp_path;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++) { /// a
            if (nums[i] > 0) {
                break;
            }
            /// 去重 a
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1, k = size - 1; j < size, k > j;) { /// b + c = -a
                if (nums[k] + nums[j] == -nums[i]) {
                    // 找到一个符合条件的三元组
                    res.push_back({nums[i], nums[j], nums[k]});
                    /// 去重 b c
                    while (j + 1 < size && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;
                    while (k - 1 >= j && nums[k - 1] == nums[k]) {
                        k--;
                    }
                    k--;

                } else if (nums[k] + nums[j] > -nums[i]) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return res;
    }


};

#endif //FH_A01_15_三数之和_H
