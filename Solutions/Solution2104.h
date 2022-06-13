//
// Created by hpf on 22-6-13.
//

#ifndef FH_A01_SOLUTION2104_H
#define FH_A01_SOLUTION2104_H

#include "../Common.h"
//2104. 子数组范围和 mid 单调栈
//给你一个整数数组 nums 。nums 中，子数组的 范围 是子数组中最大元素和最小元素的差值。
//
//返回 nums 中 所有 子数组范围的 和 。
//
//子数组是数组中一个连续 非空 的元素序列。

/**
 * 单调栈的使用
 * 所有子数组的最大值 - 所有子数组的最小值
 * 四个数组：minLeft, minRight, maxLeft, maxRight 存放每个num左边和右边第一个最小/最大的数的下标
 * 两个栈：minStack maxStack 用来辅助构建上述四个数组，栈中最后存的数据满足 i>j nums[i]>num[j]，所以叫单调栈
 *
 */
class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        int size = nums.size();
        vector<int> minLeft(size), minRight(size), maxLeft(size), maxRight(size);
        stack<int> minStack, maxStack;
        // 从左向右遍历可以找到左边第一个最小/最大的数
        for (int i = 0; i < size; ++i) {
            while (!minStack.empty() && nums[minStack.top()] >  nums[i]) {
                minStack.pop();
            }
            minLeft[i] = minStack.empty() ? -1 : minStack.top();// 左边第一个最小的数的下标
            minStack.push(i);
            cout<<"minLeft["<<i<<"] "<<minLeft[i]<<endl;
            while (!maxStack.empty() && nums[maxStack.top()] <= nums[i]) {
                maxStack.pop();
            }
            maxLeft[i] = maxStack.empty() ? -1 : maxStack.top(); // 左边第一个最大的数的下标
            maxStack.push(i);
            cout<<"maxLeft["<<i<<"] "<<maxLeft[i]<<endl;
        }
        minStack = stack<int>();
        maxStack = stack<int>();
        // 从右向左遍历可以找到右边第一个最小/最大的数
        for (int i = size - 1; i >= 0; --i) {
            while (!minStack.empty() && nums[minStack.top()] >= nums[i]) {
                minStack.pop();
            }
            minRight[i] = minStack.empty() ? size : minStack.top();// 右边第一个最小的数的下标
            minStack.push(i);
            cout<<"minRight["<<i<<"] "<<minRight[i]<<endl;

            while (!maxStack.empty() && nums[maxStack.top()] < nums[i]) {
                maxStack.pop();
            }
            maxRight[i] = maxStack.empty() ? size : maxStack.top(); // 右边第一个最大的数的下标
            maxStack.push(i);
            cout<<"maxRight["<<i<<"] "<<maxRight[i]<<endl;
        }
        // 求所有子数组的最大值 - 所有子数组的最小值
        long long minSum=0, maxSum=0;
        for (long long i = 0; i < size; ++i) {
            minSum += (i - minLeft[i]) * (minRight[i] - i) * nums[i];
            maxSum += (i - maxLeft[i]) * (maxRight[i] - i) * nums[i];
        }
        return maxSum - minSum;
    }
};

// 考虑相等情况的处理
// 为了使子数组的最大最小值唯一，定义如果nums[i] == nums[j]，如果 i < j，那么nums[i] 逻辑上 < nums[j]
// 如果 nums[maxStack.top()] == nums[i], 那么根据定义，
// nums[maxStack.top()] 逻辑上小于 nums[i]，因为 maxStack.top() < i
// 如果 nums[minStack.top()] == nums[i], 那么根据定义，
// nums[minStack.top()] 逻辑上大于 nums[i]，因为 minStack.top() > i


#endif //FH_A01_SOLUTION2104_H
