//
// Created by hpf on 22-6-10.
//

#ifndef FH_A01_SOLUTION1512_H
#define FH_A01_SOLUTION1512_H

#include "../Common.h"
//1512. 好数对的数目 ez
//给你一个整数数组 nums 。
//
//如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。
//
//返回好数对的数目。

/**
 * 寻找相等的数，求C(n,2)
 */
class Solution {
public:
    int numIdenticalPairs(vector<int> &nums) {
        // 统计字符数量
        unordered_map<int, int> numSumMap;
        for (const auto &num: nums) {
            ++numSumMap[num];
        }
        // 计算好数对
        int res = 0;
        for (const auto &numSum: numSumMap) {
            res += numSum.second * (numSum.second -1 )/2;
        }
        return res;
    }
};

#endif //FH_A01_SOLUTION1512_H
