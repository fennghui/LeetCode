//
// Created by irisfeng on 2022/7/13.
//

#ifndef FH_A01_剑指_OFFER_51_H
#define FH_A01_剑指_OFFER_51_H

#include "../Common.h"

//剑指 Offer 51. 数组中的逆序对 hard
//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

class Solution {
public:
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n-1);
    }

    // 归并排序的过程中计算逆序对
    int mergeSort(vector<int> &nums, vector<int> &tmp, int left, int right) {
        if (right <= left) {
            return 0; // if one number, the num of reversePairs is 0
        }
        int mid = (left + right) / 2;
        int res = mergeSort(nums, tmp, left, mid) + mergeSort(nums, tmp, mid + 1, right);

        for(int k = left; k <= right; ++k){
            tmp[k] = nums[k];
        }

        int i = left, j = mid + 1;
        int index = left;

        while (i <= mid && j <= right) {
            if (tmp[i] <= tmp[j]) {
                nums[index++] = tmp[i];
                ++i;
            }else{
                nums[index++] = tmp[j];
                res += mid - i + 1;
                ++j;
            }
        }
        while(i <= mid){
            nums[index++] = tmp[i++];
        }
        while(j <= right){
            nums[index++] = tmp[j++];
        }

        return res;
    }
};

#endif //FH_A01_剑指_OFFER_51_H
