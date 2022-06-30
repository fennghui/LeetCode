//
// Created by hpf on 22-6-30.
//

#ifndef FH_A01_剑指_OFFER_61_H
#define FH_A01_剑指_OFFER_61_H

#include "../Common.h"

//剑指 Offer 61. 扑克牌中的顺子 ez
//从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

class Solution {
public:
    bool isStraight(vector<int> &nums) {
        vector<int> flag(14, 0);
        for (const auto &num: nums) {
            ++flag[num];
        }
        int i = 1;
        while(i < flag.size()){
            if(flag[i] != 0){
                break;
            }
            ++i;
        }
        int cnt = 0;
        for (int j = i; j < i + 5 && j < flag.size(); ++j) {
            if (flag[j] == 1) {
                ++cnt;
            } else if (flag[j] > 1) {
                return false;
            }
        }
        if (cnt + flag[0] == 5) {
            return true;
        }
        return false;
    }
};

#endif //FH_A01_剑指_OFFER_61_H
