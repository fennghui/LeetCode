//
// Created by hpf on 22-6-29.
//

#ifndef FH_A01_剑指_OFFER_57_II_H
#define FH_A01_剑指_OFFER_57_II_H

#include "../Common.h"

//剑指 Offer 57 - II. 和为s的连续正数序列 ez
//输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
//
//序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        int left = 1;
        int right = 2;
        int sum = left + right;
        while (left <= (target / 2)) {
            if (sum < target) {
                ++right;
                sum += right;
            } else if (sum > target) {
                sum -= left;
                ++left;
            } else {
                vector<int> tmp(right - left + 1);
                for (int i = 0; i < tmp.size(); ++i) {
                    tmp[i] = left + i;
                }
                result.push_back(tmp);
                sum -= left;
                ++left;
            }
        }
        return result;
    }
};

#endif //FH_A01_剑指_OFFER_57_II_H
