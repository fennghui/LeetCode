//
// Created by irisfeng on 2023/2/21.
//

#ifndef FH_A01_454_四数相加_II_H
#define FH_A01_454_四数相加_II_H

#include "../Common.h"

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int n = nums1.size();
        int count = 0;
        unordered_map<int, int> umap; /// a+b, value num
        for (auto &a: nums1) {
            for (auto &b: nums2) {
                ++umap[a + b];
            }
        }
        for (auto &c: nums3) {
            for (auto &d: nums4) {
                count += umap[0-(c+d)];
            }
        }

        return count;
    }
};

#endif //FH_A01_454_四数相加_II_H
