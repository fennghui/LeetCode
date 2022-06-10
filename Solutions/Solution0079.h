//
// Created by hpf on 22-6-5.
//

#ifndef FH_A01_SOLUTION0079_H
#define FH_A01_SOLUTION0079_H

#include "../Common.h"
//79. 单词搜索

//给定一个m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

/**
 * 回溯法
 */
class Solution {
    long rows_;
    long cols_;
public:
    bool exist(vector<vector<char>> &board, string word) {
        rows_ = board.size();
        cols_ = board[0].size();
        vector<vector<bool>> flag(rows_, vector<bool>(cols_, false));

        // need double circulation
        for (long i = 0; i < rows_; ++i) {
            for (long j = 0; j < cols_; ++j) {
                if (dfs(board, word, flag, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isValid(int x, int y) {
        if (x < 0 || y < 0 || x > rows_ - 1 || y > cols_ - 1) {
            return false;
        }
        return true;
    }

    bool dfs(vector<vector<char>> &board, string &word,
             vector<vector<bool>> &flag, int x, int y, int no) {
        if (no > word.length() - 1) {
            return true;
        }
        //  cout<<"x:"<<x<<" y:"<<y<<" no:"<<no<<endl;
        if (isValid(x, y) && !flag[x][y] && board[x][y] == word[no]) {
            flag[x][y] = true;
            // 当前点符合条件，继续向下遍历
            if (dfs(board, word, flag, x + 1, y, no + 1))
                return true;
            if (dfs(board, word, flag, x - 1, y, no + 1))
                return true;
            if (dfs(board, word, flag, x, y + 1, no + 1))
                return true;
            if (dfs(board, word, flag, x, y - 1, no + 1))
                return true;
            flag[x][y] = false;
        }

        return false;
    }


};

#endif //FH_A01_SOLUTION0079_H
