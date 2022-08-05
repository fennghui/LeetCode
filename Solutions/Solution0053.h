//
// Created by irisfeng on 2022/8/5.
//

#ifndef FH_A01_SOLUTION0053_H
#define FH_A01_SOLUTION0053_H

#include "../Common.h"

//53. 最大子数组和 mid
//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
//子数组 是数组中的一个连续部分。

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res = INT32_MIN;
        int partialSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            partialSum += nums[i];
            if (partialSum > res) {
                res = partialSum;
            }
            if(partialSum <= 0) partialSum = 0;
        }
        return res;
    }

};

#endif //FH_A01_SOLUTION0053_H
