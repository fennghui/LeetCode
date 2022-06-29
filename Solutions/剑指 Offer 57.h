//
// Created by hpf on 22-6-29.
//

#ifndef FH_A01_剑指_OFFER_57_H
#define FH_A01_剑指_OFFER_57_H

#include "../Common.h"

//剑指 Offer 57. 和为s的两个数字 ez
//输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if((nums[left] + nums[right]) < target){
                ++left;
            }else if((nums[left] + nums[right]) > target){
                --right;
            }else{
                return {nums[left], nums[right]};
            }
        }
        return {};
    }
};

#endif //FH_A01_剑指_OFFER_57_H
