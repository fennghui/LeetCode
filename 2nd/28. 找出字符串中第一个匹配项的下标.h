//
// Created by irisfeng on 2023/2/19.
//

#ifndef FH_A01_28_找出字符串中第一个匹配项的下标_H
#define FH_A01_28_找出字符串中第一个匹配项的下标_H

#include "../Common.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hSize = haystack.size();
        int nSize = needle.size();
        for (int i = 0; i < hSize - nSize + 1; ++i) {
            if (haystack[i] == needle[0] && haystack.substr(i, nSize) == needle){
                return i;
            }
        }
        return -1;
    }
};

#endif //FH_A01_28_找出字符串中第一个匹配项的下标_H
