//
// Created by irisfeng on 2023/1/20.
//

#ifndef FH_A01_53_最大子数组和_H
#define FH_A01_53_最大子数组和_H

#include "../Common.h"

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> partialSum(n);
        partialSum[0] = nums[0];
        int maxSum = partialSum[0];
        for (int i = 1; i < n; i++) {
            partialSum[i] = (partialSum[i - 1] + nums[i] < nums[i]) ? nums[i] : partialSum[i - 1] + nums[i];
            if(partialSum[i] > maxSum){
                maxSum = partialSum[i];
            }
        }
        return maxSum;
    }
};

#endif //FH_A01_53_最大子数组和_H
