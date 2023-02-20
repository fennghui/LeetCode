//
// Created by irisfeng on 2023/2/20.
//

#ifndef FH_A01_207_课程表_H
#define FH_A01_207_课程表_H

#include "../Common.h"

class Solution {
public:
    vector<vector<int>> edges; /// 边
    vector<int> indeg; /// 存储每门课的入度

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (auto &info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]]; /// 入度+1
        }
        /// 寻找入度为 0 的点入队列
        int num = 0;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
                ++num;
            }
        }
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (auto edge: edges[top]) {
                if (--indeg[edge] == 0) {
                    q.push(edge);
                    ++num;
                }
            }
        }
        return num == numCourses;
    }
};

#endif //FH_A01_207_课程表_H
