//
// Created by irisfeng on 2022/8/5.
//

#ifndef FH_A01_SOLUTION0055_H
#define FH_A01_SOLUTION0055_H

#include "../Common.h"

//55. 跳跃游戏 mid
//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
//
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//判断你是否能够到达最后一个下标。

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curMaxJump = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(curMaxJump > 0) --curMaxJump;
            else return false;

            if(nums[i] > curMaxJump){
                curMaxJump = nums[i];
            }

            if(curMaxJump >= nums.size() -1 - i){
                return true;
            }
        }
        return true;
    }
};

#endif //FH_A01_SOLUTION0055_H
