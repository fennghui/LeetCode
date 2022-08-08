//
// Created by irisfeng on 2022/8/8.
//

#ifndef FH_A01_SOLUTION0435_H
#define FH_A01_SOLUTION0435_H

#include "../Common.h"

//435. 无重叠区间 mid
//给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 1;
        for (int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] < intervals[i-1][1]){
                res++;
            }else{
               intervals[i][1] = min(intervals[i][1], intervals[i-1][1]);
            }
        }
        return intervals.size() - res;
    }
};

#endif //FH_A01_SOLUTION0435_H
