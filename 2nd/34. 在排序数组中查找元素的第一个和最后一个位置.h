//
// Created by irisfeng on 2023/1/28.
//

#ifndef FH_A01_34_在排序数组中查找元素的第一个和最后一个位置_H
#define FH_A01_34_在排序数组中查找元素的第一个和最后一个位置_H

#include "../Common.h"

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int right_border = -2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
                right_border = left;
            }
        }
        right_border--;
        if (right_border >= nums.size() || right_border < 0 || nums[right_border] != target) {
            right_border = -1;
        }

        left = 0;
        right = nums.size() - 1;
        int left_border = -2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
                left_border = right;
            }
        }
        left_border++;
        if (left_border >= nums.size() || left_border < 0 || nums[left_border] != target) {
            left_border = -1;
        }
        return {left_border, right_border};
    }
};

#endif //FH_A01_34_在排序数组中查找元素的第一个和最后一个位置_H
