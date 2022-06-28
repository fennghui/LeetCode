//
// Created by hpf on 22-6-28.
//

#ifndef FH_A01_剑指_OFFER_42_H
#define FH_A01_剑指_OFFER_42_H

#include "../Common.h"

//剑指 Offer 42. 连续子数组的最大和
//输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
//
//要求时间复杂度为O(n)。

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> maxArray(n);
        maxArray[0] = nums[0];
        int result = maxArray[0];
        for (int i = 1; i < n; ++i) {
            maxArray[i] = max(maxArray[i-1]+nums[i],nums[i]);
            if(result < maxArray[i])
                result = maxArray[i];
        }
        return result;
    }
};

#endif //FH_A01_剑指_OFFER_42_H
