//
// Created by hpf on 22-6-11.
//

#ifndef FH_A01_SOLUTION1005_H
#define FH_A01_SOLUTION1005_H

#include "../Common.h"
//1005. K 次取反后最大化的数组和 ez
//给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
//
//选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
//重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
//
//以这种方式修改数组后，返回数组 可能的最大和 。

class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        int minusCount = 0;
        int minusSum = 0;
        int sum = 0;
        int absMin = INT32_MAX;
        // 建立负数的小顶堆
        priority_queue<int, vector<int>, greater<int>> smallHeap;
        for (const auto &num: nums) {
            sum += num;
            if (num < 0) {
                ++minusCount;
                minusSum += num;
                smallHeap.push(num);
            }
            if (abs(num) < absMin) {
                absMin = abs(num);
            }
        }
        if (k >= minusCount) {
            sum += 2 * (-minusSum);
            sum -=  2 * absMin * ((k-minusCount) % 2);
            return sum;
        }
        for (int i = 0; i < k; ++i) {
            int temp = smallHeap.top();
            sum += 2 * (-temp);
            smallHeap.pop();
        }
        return sum;
    }
};

// 默认是大顶堆，小顶堆需要显式写明

#endif //FH_A01_SOLUTION1005_H
