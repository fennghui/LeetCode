//
// Created by irisfeng on 2023/2/19.
//

#ifndef FH_A01_221_最大正方形_H
#define FH_A01_221_最大正方形_H

#include "../Common.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        /// 以 i,j 为右下角的最大正方形边长
        int col = matrix[0].size();
        int row = matrix.size();
        int maxEdge = 0
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int i = 0; i < col; ++i) {
            if (matrix[0][i] == '1') {
                dp[0][i] = 1;
                maxEdge = 1;
            }
        }
        for (int i = 0; i < row; ++i) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                maxEdge = 1;
            }
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    maxEdge = max(dp[i][j], maxEdge);
                }
            }
        }
        return maxEdge * maxEdge;
    }
};

#endif //FH_A01_221_最大正方形_H
