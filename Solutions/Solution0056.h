//
// Created by irisfeng on 2022/8/8.
//

#ifndef FH_A01_SOLUTION0056_H
#define FH_A01_SOLUTION0056_H

#include "../Common.h"

//56. 合并区间 mid
//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
//请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > intervals[i-1][1]){
                res.push_back(intervals[i-1]);
            }else{
                intervals[i][1] = max(intervals[i][1], intervals[i-1][1]);
                intervals[i][0] = intervals[i-1][0];
            }
        }
        res.push_back(intervals[intervals.size()-1]);
        return res;
    }
};

#endif //FH_A01_SOLUTION0056_H
