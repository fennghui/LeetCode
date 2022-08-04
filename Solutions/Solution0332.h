//
// Created by irisfeng on 2022/8/4.
//

#ifndef FH_A01_SOLUTION0332_H
#define FH_A01_SOLUTION0332_H

#include "../Common.h"

//332. 重新安排行程 hard
//给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
//
//所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
//
//例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
//假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

/**
 * unordered_map<string, map<string,int>> targets;
 * 这个数据结构很有意思
 */
class Solution {
public:
    unordered_map<string, map<string,int>> targets;
    vector<string> path;

    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for(auto &ticket : tickets){
            targets[ticket[0]][ticket[1]]++;
        }
        path.push_back("JFK");
        backtracking(tickets);
        return path;
    }

    bool backtracking(vector<vector<string>> &tickets) {
        if (path.size() == tickets.size() + 1) {
            // 判断 path 和 res 的字典序大小，看是否需要更新
            return true;
        }

        for (auto &target : targets[path.back()]){
            if(target.second > 0){
                path.push_back(target.first);
                --target.second;
                if(backtracking(tickets)) return true;
                ++target.second;
                path.pop_back();
            }
        }
        return false;
    }
};
#endif //FH_A01_SOLUTION0332_H
