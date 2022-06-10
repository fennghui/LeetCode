//
// Created by hpf on 22-6-4.
//

#ifndef FH_A01_SOLUTION0135_H
#define FH_A01_SOLUTION0135_H

#include "../Common.h"


//n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
//
//你需要按照以下要求，给这些孩子分发糖果：
//
//每个孩子至少分配到 1 个糖果。
//相邻两个孩子评分更高的孩子会获得更多的糖果。
//请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

/**
 * 从左向右遍历，保证当前孩子和左边孩子满足要求
 * 从右向左遍历，保证当前孩子和右边孩子满足要求
 * 这种两边遍历的方法适用于什么类型的题呢？
 */
class Solution {
public:
    int candy(vector<int> &ratings) {
        auto size = static_cast<int>(ratings.size());
        vector<int> candy(size, 1);
        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        // 注意，倒序循环的时候，循环变量一定不能是无符号数，不然会一直满足>=0的条件，循环无法终止
        for (int i = size - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = candy[i] > candy[i + 1] + 1 ? candy[i] : candy[i + 1] + 1;
            }
        }

        // 求和
        int result = 0;
        for (auto &it: candy) {
            result += it;
        }
        return result;
    }
};

#endif //FH_A01_SOLUTION0135_H
