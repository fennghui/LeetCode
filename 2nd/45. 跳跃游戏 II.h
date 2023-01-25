//
// Created by irisfeng on 2023/1/25.
//

#ifndef FH_A01_45_跳跃游戏_II_H
#define FH_A01_45_跳跃游戏_II_H

#include "../Common.h"

class Solution {
public:
    int jump(vector<int> &nums) {
        int curCoverDis = 0;
        int nextCoverDis = 0;
        int jumpNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            nextCoverDis = max(nextCoverDis, nums[i] + i);
            if (i == curCoverDis){
                if(i != nums.size() - 1){
                    jumpNum++;
                    curCoverDis = nextCoverDis;
                    if(curCoverDis >= nums.size() - 1){ /// 已经可以覆盖全部范围
                        break;
                    }
                }else{
                    break;
                }
            }
        }
        return jumpNum;
    }
};

#endif //FH_A01_45_跳跃游戏_II_H
