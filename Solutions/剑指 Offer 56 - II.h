//
// Created by iris on 22-7-11.
//

#ifndef FH_A01_剑指_OFFER_56_II_H
#define FH_A01_剑指_OFFER_56_II_H

#include "../Common.h"

//剑指 Offer 56 - II. 数组中数字出现的次数 II mid
//在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

class Solution {
public:
    // 位运算
    int singleNumber(vector<int> &nums) {
        vector<int> count(32, 0);
        for (auto &num: nums) {
            for (int i = 0; i < 32; ++i) {
                count[i] += num & 1;
                num = num >> 1;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res = res << 1;
            res = res | (count[31 - i] % 3);
        }
        return res;
    }
};

//int singleNumber(vector<int> &nums) {
//    unordered_map<int, int> umap;
//    for (const auto &num: nums) {
//        umap[num]++;
//    }
//    for (const auto &iter: umap) {
//        if (iter.second == 1) {
//            return iter.first;
//        }
//    }
//    return 0;
//}

#endif //FH_A01_剑指_OFFER_56_II_H
