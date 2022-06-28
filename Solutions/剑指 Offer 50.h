//
// Created by hpf on 22-6-28.
//

#ifndef FH_A01_剑指_OFFER_50_H
#define FH_A01_剑指_OFFER_50_H

#include "../Common.h"

//剑指 Offer 50. 第一个只出现一次的字符 ez
//在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

class Solution {
public:
    char firstUniqChar(string s) {
        if (s == "")
            return ' ';
        vector<int> visited(26, 0);
        vector<int> firstIndex(26, -1);
        int charIndex = INT32_MAX;
        char charFirst = ' ';
        for (int i = 0; i < s.size(); ++i) {
            ++visited[s[i] - 'a'];
            if (firstIndex[s[i] - 'a'] == -1)
                firstIndex[s[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; ++i) {
            if (visited[i] == 1) {
                if (firstIndex[i] >= 0 && firstIndex[i] < charIndex) {
                    charIndex = firstIndex[i];
                    charFirst = i + 'a';
                }
            }
        }
        return charFirst;
    }
};

#endif //FH_A01_剑指_OFFER_50_H
