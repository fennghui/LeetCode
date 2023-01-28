//
// Created by irisfeng on 2023/1/28.
//

#ifndef FH_A01_54_螺旋矩阵_H
#define FH_A01_54_螺旋矩阵_H

#include "../Common.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 1) {
            return matrix[0];
        }
        int n = matrix[0].size();
        vector<int> res;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        /// 初始方向
        int a = 0, b = 1;
        int x = 0, y = 0;
        int total = m * n;
        for (int i = 0; i < total; i++) {
//            cout << "x " << x << " y " << y << endl;
            res.push_back(matrix[x][y]);
            visited[x][y] = true;
            int nextX = x + a;
            int nextY = y + b;
            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || visited[nextX][nextY]) {
                int newA = b;
                int newB = -a;
                a = newA;
                b = newB;
            }
            x += a;
            y += b;
        }
        return res;
    }
};

#endif //FH_A01_54_螺旋矩阵_H
