//
// Created by hpf on 22-6-10.
//

#ifndef FH_A01_SOLUTION0063_H
#define FH_A01_SOLUTION0063_H

#include "../Common.h"

//63. 不同路径 II mid
//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
//
//现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
//
//网格中的障碍物和空位置分别用 1 和 0 来表示。

class Solution {
    int rows_;
    int cols_;
public:

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }
        rows_ = obstacleGrid.size();
        cols_ = obstacleGrid[0].size();
        vector<vector<int>> result(rows_, vector<int>(cols_, 0));

        // generate boundary value
        result[0][0] = obstacleGrid[0][0]?0:1;
        for (int i = 1; i < cols_; ++i) {
            result[0][i] = obstacleGrid[0][i]?0:result[0][i-1];
        }
        for (int i = 1; i < rows_; ++i) {
            result[i][0] = obstacleGrid[i][0]?0:result[i-1][0];
        }
        for (int i = 1; i < rows_; ++i) {
            for (int j = 1; j < cols_; ++j) {
                result[i][j] = obstacleGrid[i][j]?0:result[i - 1][j] + result[i][j - 1];
            }
        }
        return result[rows_ - 1][cols_ - 1];
    }
};

// 一个动态规划问题

#endif //FH_A01_SOLUTION0063_H
