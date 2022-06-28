//
// Created by hpf on 22-6-28.
//

#ifndef FH_A01_剑指_OFFER_53_I_H
#define FH_A01_剑指_OFFER_53_I_H

#include "../Common.h"
//剑指 Offer 53 - I. 在排序数组中查找数字 I ez
//统计一个数字在排序数组中出现的次数。

class SolutionGF {
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return rightIdx - leftIdx + 1;
        }
        return 0;
    }
};


class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.size() == 0)
            return 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 2);
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                left = mid;
                break;
            } else {
                left = mid + 1;
            }
        }
        if (left > nums.size() - 1 || nums[left] != target) {
            return 0;
        }

        int indexL = left;
        int indexR = left;
        while (indexL >= 0 && nums[indexL] == target) {
            --indexL;
        }
        while (indexR <= nums.size() - 1 && nums[indexR] == target) {
            ++indexR;
        }
        return indexR - indexL - 1;
    }
};

#endif //FH_A01_剑指_OFFER_53_I_H
