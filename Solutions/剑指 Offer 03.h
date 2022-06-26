//
// Created by hpf on 22-6-26.
//

#ifndef FH_A01_剑指_OFFER_03_H
#define FH_A01_剑指_OFFER_03_H

#include "../Common.h"

//剑指 Offer 03. 数组中重复的数字
//找出数组中重复的数字。
//
//
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> isExist(n);
        for(int i=0;i<n;++i){
            if(isExist[nums[i]] == 1){
                return nums[i];
            }else{
                isExist[nums[i]] = 1;
            }
        }
        return 0;
    }
};

#endif //FH_A01_剑指_OFFER_03_H
