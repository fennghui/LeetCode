//
// Created by hpf on 22-6-15.
//

#ifndef FH_A01_SOLUTION0003_H
#define FH_A01_SOLUTION0003_H

#include "../Common.h"
//3. 无重复字符的最长子串 mid 经典双指针
//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

/**
 * 经典双指针
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSubLen = 0;
        int prev = 0;
        unordered_set<char> subChar;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (subChar.find(s[i]) == subChar.end()) {
                //未在set中找到重复的
                subChar.emplace(s[i]);
            } else {
                //找到重复的，将prev指针定位到重复的元素上
                if ((i - prev) > maxSubLen) {
                    maxSubLen = i - prev;
                }
                for (int j = prev; j < i; ++j) {
                    if(s[j]==s[i]){
                        prev = j+1;
                        break;
                    }else{
                        subChar.erase(s[j]);
                    };
                }
            }
        }
        if ((n - prev) > maxSubLen) {
            maxSubLen = n - prev;
        }
        return maxSubLen;
    }
};

#endif //FH_A01_SOLUTION0003_H
