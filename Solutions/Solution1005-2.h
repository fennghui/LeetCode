//
// Created by irisfeng on 2022/8/6.
//

#ifndef FH_A01_SOLUTION1005_2_H
#define FH_A01_SOLUTION1005_2_H

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
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                --k;
            }
            sum += nums[i];
        }
        if (k % 2 == 1) {
            sum -= 2 * nums.back();
        }
        return sum;
    }
};

#endif //FH_A01_SOLUTION1005_2_H
