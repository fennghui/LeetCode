//
// Created by irisfeng on 2023/2/21.
//

#ifndef FH_A01_792_匹配子序列的单词数_H
#define FH_A01_792_匹配子序列的单词数_H

#include "../Common.h"

class Solution {
public:
    int numMatchingSubseq(string s, vector<string> &words) {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]].push_back(i);
        }
        int res = 0;
        for (auto &word: words) {
            int lastIndex = -1;
            bool isSubSeq = true;
            for (auto &letter: word) {
                if (mp.find(letter) == mp.end()) {
                    isSubSeq = false;
                    break;
                } else {
                    bool flag = false;
                    auto value = upper_bound(mp[letter].begin(),mp[letter].end(),lastIndex);
                    if(value != mp[letter].end()){
                        lastIndex = *value;
                        flag = true;
                    }
                    /// 下面超时，考虑二分找第一个大于 lastIndex 的值，但是这个二分还是写不对，干脆用
                    /// STL 提供的函数 upper_bound 了，但是二分还是得会
//                    for (auto &index: mp[letter]) { /// 遍历每一个可能的 index
//                        if (index > lastIndex) {
//                            lastIndex = index;
//                            flag = true;
//                            break;
//                        }
//                    }
                    if (!flag) {
                        isSubSeq = false;
                        break;
                    }
                }
            }
            if (isSubSeq) {
                ++res;
            }
        }
        return res;
    }
};

#endif //FH_A01_792_匹配子序列的单词数_H
