//
// Created by irisfeng on 2023/1/29.
//

#ifndef FH_A01_77_组合_H
#define FH_A01_77_组合_H

#include "../Common.h"

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        backTracking(n, k, 1, 0);
        return res;
    }

    void backTracking(int n, int k, int startIndex, int curLen) {
        if (curLen >= k) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; ++i) {
            path.push_back(startIndex);
            backTracking(n, k, i+1, curLen+1);
            path.pop_back();
        }
    }
};

#endif //FH_A01_77_组合_H
