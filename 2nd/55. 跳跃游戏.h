//
// Created by irisfeng on 2023/1/25.
//

#ifndef FH_A01_55_跳跃游戏_H
#define FH_A01_55_跳跃游戏_H

#include "../Common.h"

/**
 * 输入：nums = [2,3,1,1,4]
 * 输出：true
 */

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        int curMaxJump = nums[0]; /// 当前可以跳跃的最大步数
        for (int i = 1; i < n; i++) { /// 一步一步模拟跳完全程
            if(curMaxJump > 0){ // 还可以跳
                curMaxJump--;
            }else{
                return false;
            }
            /// 更新当前可以跳跃的最大步数
            if(nums[i] > curMaxJump){
                curMaxJump = nums[i];
            }
            /// 做剪枝
            if(i + curMaxJump >= n - 1){
                return true;
            }
        }
        return true;
    }
};

#endif //FH_A01_55_跳跃游戏_H
