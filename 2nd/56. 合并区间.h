//
// Created by irisfeng on 2023/1/26.
//

#ifndef FH_A01_56_合并区间_H
#define FH_A01_56_合并区间_H

#include "../Common.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.size() == 0) {
            return {};
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        vector<vector<int>> res;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end && intervals[i][1] >= start) {
                /// 可以合并
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            } else {
                /// 不可合并
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        res.push_back({start, end});

        return res;
    }
};

#endif //FH_A01_56_合并区间_H
