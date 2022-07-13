//
// Created by irisfeng on 2022/7/12.
//

#ifndef FH_A01_剑指_OFFER_56_I_H
#define FH_A01_剑指_OFFER_56_I_H

#include "../Common.h"

//剑指 Offer 56 - I. 数组中数字出现的次数 mid
//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums) {
        int a = 0, m = 1;
        for (int num: nums) {
            a ^= num;
        }
        while ((a & m) == 0)
            m <<= 1;

        int x = 0, y = 0;
        for (int num: nums) {
            if(num & m) // 注意这里易错
                x ^= num;
            else
                y ^= num;
        }
        return vector<int>{x, y};
    }
};

#endif //FH_A01_剑指_OFFER_56_I_H
