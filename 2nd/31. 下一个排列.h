//
// Created by irisfeng on 2023/1/26.
//

#ifndef FH_A01_31_下一个排列_H
#define FH_A01_31_下一个排列_H

#include "../Common.h"

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i;
        /// 从后往前遍历，寻找第一个不符合升序的数字
        for (i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                /// 需要找到该数字之后大于它且和它差值最小的那个数做交换
                int j = i + 1;
                while (j < nums.size() && nums[j] > nums[i]) {
                    j++;
                }
                j--;
                swap(nums[i], nums[j]);
                break;
            }
            /// 否则，继续遍历
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

#endif //FH_A01_31_下一个排列_H
