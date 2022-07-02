//
// Created by hpf on 22-7-2.
//

#ifndef FH_A01_剑指_OFFER_13_H
#define FH_A01_剑指_OFFER_13_H

#include "../Common.h"

//剑指 Offer 13. 机器人的运动范围 mid
//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
//一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
//也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，
//因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

/**
 * 广度优先搜索
 */
class Solution {
    int grids_num = 0;
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        dfs(m, n, k, flag, 0, 0);
        return grids_num;
    }

    int sumANum(int x) {
        int res = 0;
        while (x != 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }

    void dfs(int m, int n, int k, vector<vector<bool>> &flag, int x, int y) {
        flag[x][y] = true;
        if (sumANum(x) + sumANum(y) > k) {
            return;
        }
        ++grids_num;
        vector<pair<int, int>> directions{{0,  1},
                                          {1,  0}};
        for (const auto &dir: directions) {
            int newx = x + dir.first;
            int newy = y + dir.second;
            if (newx >= 0 && newy >= 0 && newx < m && newy < n && !flag[newx][newy])
                dfs(m, n, k, flag, newx, newy);
        }
    }
};

#endif //FH_A01_剑指_OFFER_13_H
