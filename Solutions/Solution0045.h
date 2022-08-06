//
// Created by irisfeng on 2022/8/5.
//

#ifndef FH_A01_SOLUTION0045_H
#define FH_A01_SOLUTION0045_H

#include "../Common.h"

//45. 跳跃游戏 II mid
//给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
//
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//你的目标是使用最少的跳跃次数到达数组的最后一个位置。
//
//假设你总是可以到达数组的最后一个位置。

class Solution {
public:
    int jump(vector<int> &nums) {
        int curCoverDis = 0;
        int nextCoverDis = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nextCoverDis = max(nums[i] + i, nextCoverDis);
            if (i == curCoverDis) {
                if (i != nums.size() - 1) {
                    ++res;
                    curCoverDis = nextCoverDis;
                    if (curCoverDis >= nums.size() - 1) break;
                } else break;
            }
        }
        return res;
    }
};

#endif //FH_A01_SOLUTION0045_H
