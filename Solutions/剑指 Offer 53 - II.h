//
// Created by hpf on 22-6-29.
//

#ifndef FH_A01_剑指_OFFER_53_II_H
#define FH_A01_剑指_OFFER_53_II_H

#include "../Common.h"

//剑指 Offer 53 - II. 0～n-1中缺失的数字
//一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int ans = nums.size();
        while(left<=right){
            int mid = (left + right) / 2;
            if(nums[mid] > mid){
                right = mid - 1;
                ans = mid;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};


#endif //FH_A01_剑指_OFFER_53_II_H
