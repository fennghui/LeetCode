//
// Created by irisfeng on 2023/1/26.
//

#ifndef FH_A01_560_和为_K_的子数组_H
#define FH_A01_560_和为_K_的子数组_H

#include "../Common.h"

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        /**
         * 方法一：枚举（超出时间限制）
         */
//        int count = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            int sum = 0;
//            for (int j = i; j >= 0; j--) {
//                sum += nums[i];
//                if (sum == k) {
//                    count++;
//                }
//            }
//        }
//        return count;

        /**
         * 方法二：前缀和 哈希表优化
         */
        unordered_map<int, int> sub_sum_map; // 保存出现过的累积和 sum 的次数
        sub_sum_map[0] = 1; // 前缀和为 0 的次数设置为 1，保证当 pre[i] = k 的时候符合条件
        int pre_sum = 0;
        int res = 0;
        for (auto &num: nums) {
             pre_sum += num;
             res += sub_sum_map[pre_sum - k];
             sub_sum_map[pre_sum]++;
        }
        return res;

    }
};

#endif //FH_A01_560_和为_K_的子数组_H
