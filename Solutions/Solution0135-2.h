//
// Created by irisfeng on 2022/8/7.
//

#ifndef FH_A01_SOLUTION0135_2_H
#define FH_A01_SOLUTION0135_2_H

#include "../Common.h"

//135. 分发糖果 hard
//n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
//
//你需要按照以下要求，给这些孩子分发糖果：
//
//每个孩子至少分配到 1 个糖果。
//相邻两个孩子评分更高的孩子会获得更多的糖果。
//请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candies(ratings.size(), 0);
        // 从左向右遍历
        candies[0] = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
            else
                candies[i] = 1;
        }

        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i + 1] + 1, candies[i]);
        }

        int res = 0;
        for (auto candy: candies) {
            res += candy;
        }
        return res;
    }
};

#endif //FH_A01_SOLUTION0135_2_H
