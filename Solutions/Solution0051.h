//
// Created by irisfeng on 2022/8/4.
//

#ifndef FH_A01_SOLUTION0051_H
#define FH_A01_SOLUTION0051_H

#include "../Common.h"

//51. N 皇后 hard
//按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
//
//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
//给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
//
//每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    vector<vector<string>> solveNQueens(int n) {
        path.assign(n, string(n, '.'));
        backtracking(n, 0);
        return res;
    }

    void backtracking(int n, int row) {
        if (row == n) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (isValid(row, i, n)) {
                path[row][i] = 'Q';
                backtracking(n, row + 1);
                path[row][i] = '.';
            }
        }
    }

    // 检查棋盘是否合法
    // 不能同一行（不会发生）
    // 不能同一列
    // 不能同一斜线
    bool isValid(int row, int col, int n) {
        // 不能同一列
        for (int i = 0; i < row; ++i) {
            if (path[i][col] == 'Q')
                return false;
        }

        // 不能左斜
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(path[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(path[i][j] == 'Q')
                return false;
        }

        return true;
    }
};

#endif //FH_A01_SOLUTION0051_H
