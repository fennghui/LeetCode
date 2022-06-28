//
// Created by hpf on 22-6-28.
//

#ifndef FH_A01_剑指_OFFER_39_H
#define FH_A01_剑指_OFFER_39_H

#include "../Common.h"

//剑指 Offer 39. 数组中出现次数超过一半的数字
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currNum = nums[0];
        int currCount = 1;
        for(int i = 1;i<nums.size();++i){
            if(nums[i] != currNum){
                if(currCount != 0){
                    --currCount;
                }
                else{
                    currNum = nums[i];
                    ++currCount;
                }
            }else{
                ++currCount;
            }
        }
        return currNum;
    }
};

#endif //FH_A01_剑指_OFFER_39_H
