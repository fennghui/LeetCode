//
// Created by hpf on 22-6-15.
//

#ifndef FH_A01_SOLUTION0215_H
#define FH_A01_SOLUTION0215_H

#include "../Common.h"

//215. 数组中的第K个最大元素 mid
//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//
//请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

/**
 * 1. 基于快排的选择方法
 * 2. 手写堆
 */
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {

    }

    int quickSelect(vector<int> &a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q==index){
            return a[q];
        }
        return q<index ? quickSelect(a, )
    }

    inline int randomPartition(vector<int> &a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int> &a, int l, int r) {

    }
};

#endif //FH_A01_SOLUTION0215_H
