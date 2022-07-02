//
// Created by hpf on 22-7-2.
//

#ifndef FH_A01_剑指_OFFER_12_H
#define FH_A01_剑指_OFFER_12_H

#include "../Common.h"

//剑指 Offer 12. 矩阵中的路径 mid
//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

class Solution {
    int row = 0;
    int col = 0;
public:
    bool exist(vector<vector<char>> &board, string word) {
        row = board.size() - 1;
        col = board[0].size() - 1;
        vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i <= row; ++i) {
            for (int j = 0; j <= col; ++j) {
                if (backtracking(board, word, flag, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtracking(vector<vector<char>> &board, string &word, vector<vector<bool>> &flag, int no, int x, int y) {
        if (x > row || x < 0 || y > col || y < 0 || board[x][y] != word[no] || flag[x][y]) {
            return false;
        }
        if (no == word.size() - 1) {
            return true;
        }

        flag[x][y] = true;
        vector<vector<int>> pos{{0,  -1},
                                {-1, 0},
                                {0,  1},
                                {1,  0}};
        for (int i = 0; i < pos.size(); ++i) {
            int newX = x + pos[i][0];
            int newY = y + pos[i][1];
            if (backtracking(board, word, flag, no + 1, newX, newY)) {
                return true;
            }
        }
        flag[x][y] = false;
        return false;
    }
};


#endif //FH_A01_剑指_OFFER_12_H
