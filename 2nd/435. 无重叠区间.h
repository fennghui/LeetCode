//
// Created by irisfeng on 2023/2/21.
//

#ifndef FH_A01_435_无重叠区间_H
#define FH_A01_435_无重叠区间_H

#include "../Common.h"

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int count = 0;
        int end = INT32_MIN;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};

#endif //FH_A01_435_无重叠区间_H
