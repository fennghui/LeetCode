//
// Created by irisfeng on 2023/1/19.
//

#ifndef FH_A01_16_最接近的三数之和_H
#define FH_A01_16_最接近的三数之和_H

#include "../Common.h"

// [2,3,8,9,10]

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < size - 2; i++) { /// a
            /// 去重 a
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1, k = size - 1; k > j;) { /// b + c = -a
                int sum = nums[i] + nums[k] + nums[j];
                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    /// 去重 c
                    while (k - 1 >= j && nums[k - 1] == nums[k]) {
                        k--;
                    }
                    k--;
                } else {
                    /// 去重 b
                    while (j + 1 < size && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;
                }

                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }
            }
        }
        return closest;
    }
};

#endif //FH_A01_16_最接近的三数之和_H
