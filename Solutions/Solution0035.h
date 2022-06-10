//
// Created by hpf on 22-6-3.
//

#ifndef FH_A01_SOLUTION0035_H
#define FH_A01_SOLUTION0035_H

#include "../Common.h"

// 35. 搜索插入位置
// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 请必须使用时间复杂度为 O(log n) 的算法

/**
 * 解题思路：二分法
 * 0, 3, 7, 5, 9, 4
 */
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int begin = 0;
        int end = static_cast<int>(nums.size()) - 1;
        int mid = 0;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (target > nums[mid]) {
                begin = mid + 1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        // 注意这里返回的应该是begin
        return begin;
    }
};

#endif //FH_A01_SOLUTION0035_H
