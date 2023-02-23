//
// Created by irisfeng on 2023/2/23.
//

#ifndef FH_A01_88_合并两个有序数组_H
#define FH_A01_88_合并两个有序数组_H

#include "../Common.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1index = m-1;
        int nums2index = n-1;
        int curIndex = m+n-1;
        while(nums1index >= 0 && nums2index >= 0){
            if(nums1[nums1index] > nums2[nums2index]){
                nums1[curIndex] = nums1[nums1index];
                --nums1index;
            }else{
                nums1[curIndex] = nums2[nums2index];
                --nums2index;
            }
            --curIndex;
        }
        while(nums2index >= 0){
            nums1[curIndex] = nums2[nums2index];
            --nums2index;
            --curIndex;
        }
    }
};

#endif //FH_A01_88_合并两个有序数组_H
