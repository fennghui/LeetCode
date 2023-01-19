//
// Created by irisfeng on 2023/1/19.
//

#ifndef FH_A01_200_岛屿数量_H
#define FH_A01_200_岛屿数量_H

#include "../Common.h"

// 回溯
/**
 * 第一次解答错误的例子
 * ["1","1","1"],
 * ["0","1","0"],
 * ["1","1","1"]
 */


class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res += 1;
                    search(grid,  i, j, m, n);
                }
            }
        }
        return res;
    }

    void search(vector<vector<char>> &grid,int x, int y, int m, int n) {
        if (grid[x][y] != '1') {
            return;
        }
        /// 搜索过的区域做一个标记
        grid[x][y] = '2';
        static vector<vector<int>> area{{0,  1},
                                 {1,  0},
                                 {-1, 0},
                                 {0,  -1}};
        for (int i = 0; i < 4; i++) {
            int new_x = x + area[i][0];
            int new_y = y + area[i][1];
            if (new_x >= 0 && new_x < m && new_y >=0 && new_y < n) {
                if (grid[new_x][new_y] == '1') {
                    search(grid, new_x, new_y, m, n);
                }
            }
        }
    }
};

#endif //FH_A01_200_岛屿数量_H
