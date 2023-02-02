//
// Created by irisfeng on 2023/2/2.
//

#ifndef FH_A01_611_有效三角形的个数_H
#define FH_A01_611_有效三角形的个数_H

#include "../Common.h"

class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        if (nums.size() < 3) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                int sum = nums[i] + nums[j];
                /// 二分查找 第一个小于 sum 的位置
                int left = j + 1;
                int right = nums.size() - 1;
                int bound = j;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] >= sum) {
                        right = mid - 1;
                    } else {
                        bound = mid;
                        left = mid + 1;
                    }
                }
                res += bound - j;
            }
        }
        return res;
    }
};

#endif //FH_A01_611_有效三角形的个数_H
