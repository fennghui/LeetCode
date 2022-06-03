//
// Created by hpf on 22-5-31.
//

#ifndef FH_A01_SOLUTION0001_H
#define FH_A01_SOLUTION0001_H

#include "../Common.h"


//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target 的那两个整数，并返回它们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//
//你可以按任意顺序返回答案

/**
 * 思路1：将数组排序，采用双指针，找到和为target的两个整数，O(n)
 * 思路2：unordered map<value, 下标>
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // 因为key是nums中的值，但这个值是可以重复的，所以一开始考虑使用multiple map
        // 但其实可以直接使用unordered map，同时也不需要先构建map
        unordered_map<int, size_t> nums_map;
        // 直接判断表中是否存在，就可以避免自查询，例如[3, 3] [3, 2, 4]这种情况
        for (size_t i = 0; i < nums.size(); ++i) {
            auto iter = nums_map.find(target - nums[i]);
            if (iter != nums_map.end()) {
                return {static_cast<int>(i), static_cast<int>(iter->second)};
            } else {
                nums_map[nums[i]] = i;
            }
        }
        return {0, 0};
    }
};

#endif //FH_A01_SOLUTION0001_H
