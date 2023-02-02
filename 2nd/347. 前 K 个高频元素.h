//
// Created by irisfeng on 2023/2/2.
//

#ifndef FH_A01_347_前_K_个高频元素_H
#define FH_A01_347_前_K_个高频元素_H

#include "../Common.h"

class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> numsMap;
        for (auto &num: nums) {
            ++numsMap[num];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto &[num, count]: numsMap) {
            if (q.size() < k) {
                q.emplace(num, count);
            } else if (count > q.top().second) {
                q.pop();
                q.emplace(num, count);
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};

#endif //FH_A01_347_前_K_个高频元素_H
