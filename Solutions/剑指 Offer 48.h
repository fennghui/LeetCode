//
// Created by irisfeng on 2022/7/13.
//

#ifndef FH_A01_剑指_OFFER_48_H
#define FH_A01_剑指_OFFER_48_H

#include "../Common.h"

//剑指 Offer 48. 最长不含重复字符的子字符串 mid
//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

//1. 动态规划
//2. 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        if(s.size() == 1)
            return 1;
        unordered_map<char, int> charToNearestPos(26);
        for (int i = 0; i < 26; ++i) {
            charToNearestPos['a' + i] = -1;
        }
        int dpPre, dpCur;
        // initial
        dpPre = 1;
        int lenMax = dpPre;
        charToNearestPos[s[0]] = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (charToNearestPos[s[i]] == -1 || (i - charToNearestPos[s[i]]) > dpPre){
                dpCur = dpPre + 1;
            }else{
                dpCur = i - charToNearestPos[s[i]];
            }
            dpPre = dpCur;
            if(dpCur > lenMax){
                lenMax = dpCur;
            }
            charToNearestPos[s[i]] = i;
        }
        return lenMax;
    }
};

#endif //FH_A01_剑指_OFFER_48_H
