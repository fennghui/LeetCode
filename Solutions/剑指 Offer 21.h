//
// Created by hpf on 22-6-26.
//

#ifndef FH_A01_剑指_OFFER_21_H
#define FH_A01_剑指_OFFER_21_H

#include "../Common.h"

//剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            while (l < r && (nums[l] & 1) == 1) {
                ++l;
            }
            while (l < r && (nums[r] & 1) == 0) {
                --r;
            }
            swap(nums[l], nums[r]);
        }
        return nums;
    }
};

#endif //FH_A01_剑指_OFFER_21_H
