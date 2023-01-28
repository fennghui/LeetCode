//
// Created by irisfeng on 2023/1/28.
//

#ifndef FH_A01_128_最长连续序列_H
#define FH_A01_128_最长连续序列_H

#include "../Common.h"

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        set<int> numSet;
        for (auto &num: nums) {
            numSet.emplace(num);
        }
        int maxLen = 0;
        for (auto &num: numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                /// 未找到，遍历，查找最长连续序列的长度
                int value = num + 1;
                int len = 1;
                while (numSet.find(value) != numSet.end()) {
                    value++;
                    len++;
                }
                if(len > maxLen){
                    maxLen = len;
                }
            }
        }
        return maxLen;
    }
};

#endif //FH_A01_128_最长连续序列_H
