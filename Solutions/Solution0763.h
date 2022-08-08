//
// Created by irisfeng on 2022/8/8.
//

#ifndef FH_A01_SOLUTION0763_H
#define FH_A01_SOLUTION0763_H

#include "../Common.h"

//763. 划分字母区间 mid
//字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> umap;
        for (int i = 0; i < s.size(); ++i) {
            umap[s[i]] = i;
        }
        vector<int> res;
        int preIndex = 0;
        int curIndex = 0;
        for (int i = 0; i < s.size(); ++i) {
            curIndex = max(curIndex, umap[s[i]]);
            if (i == curIndex) {
                res.push_back(curIndex - preIndex + 1);
                preIndex = curIndex + 1;
            }
        }

        return res;
    }
};

#endif //FH_A01_SOLUTION0763_H
