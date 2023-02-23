//
// Created by irisfeng on 2023/2/23.
//

#ifndef FH_A01_704_二分查找_H
#define FH_A01_704_二分查找_H

#include "../Common.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
};

#endif //FH_A01_704_二分查找_H
