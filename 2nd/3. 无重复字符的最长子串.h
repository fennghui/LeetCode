//
// Created by irisfeng on 2023/1/18.
//

#ifndef FH_A01_3_无重复字符的最长子串_H
#define FH_A01_3_无重复字符的最长子串_H

#include "../Common.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size<2){
            return size;
        }
        unordered_map<char, int> letter_index_map;
        int longest_len = 0;

        int left = 0;
        for (int i = 0; i < size; i++) {
            if (letter_index_map.find(s[i]) != letter_index_map.end()) { // 找到相同的
                int len = i - left;
                longest_len = (len > longest_len) ? len : longest_len;
                left = (letter_index_map[s[i]] + 1) > left ? (letter_index_map[s[i]] + 1) : left;
            }
            letter_index_map[s[i]] = i;
        }

        longest_len = ((size - left) > longest_len) ? (size - left) : longest_len;
        return longest_len;
    }
};

#endif //FH_A01_3_无重复字符的最长子串_H
