//
// Created by irisfeng on 2022/8/4.
//

#ifndef FH_A01_SOLUTION0037_H
#define FH_A01_SOLUTION0037_H

#include "../Common.h"

//37. 解数独 hard
//编写一个程序，通过填充空格来解决数独问题。
//
//数独的解法需 遵循如下规则：
//
//数字 1-9 在每一行只能出现一次。
//数字 1-9 在每一列只能出现一次。
//数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
//数独部分空格内已填入了数字，空白格用 '.' 表示。

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board, 0);
    }

    bool backtracking(vector<vector<char>>& board, int row_){
        for(int row = row_; row < board.size(); ++row){
            for(int col = 0; col < board[0].size(); ++col){
                if(board[row][col] != '.') continue;
                for(char value = '1'; value <= '9'; ++value){
                    if(isValid(board, row, col, value)){
                        board[row][col] = value;
                        if(backtracking(board, row)) return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char value){
        for(int i = 0; i < 9; ++i){
            if(board[row][i] == value)
                return false;
        }
        for(int i = 0; i < 9; ++i){
            if(board[i][col] == value)
                return false;
        }

        int startRow = row / 3 * 3;
        int startCol = col / 3 * 3;
        for(int i = startRow; i < startRow + 3; ++i){
            for(int j = startCol; j < startCol + 3; ++j){
                if(board[i][j] == value)
                    return false;
            }
        }

        return true;
    }


};

#endif //FH_A01_SOLUTION0037_H
