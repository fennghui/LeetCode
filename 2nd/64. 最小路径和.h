//
// Created by irisfeng on 2023/2/19.
//

#ifndef FH_A01_64_最小路径和_H
#define FH_A01_64_最小路径和_H

#include "../Common.h"

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += grid[0][i];
            dp[0][i] = sum;
        }
        sum = dp[0][0];
        for(int i = 1; i < m; ++i){
            sum += grid[i][0];
            dp[i][0] = sum;
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

#endif //FH_A01_64_最小路径和_H
