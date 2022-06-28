//
// Created by hpf on 22-6-28.
//

#ifndef FH_A01_剑指_OFFER_29_H
#define FH_A01_剑指_OFFER_29_H

#include "../Common.h"

//剑指 Offer 29. 顺时针打印矩阵
//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if(matrix.empty())
            return {};
        int col = matrix[0].size();
        int row = matrix.size();
        int direction = 0;// 右、下、左、上  0, 1, 2, 3
        int x = 0, y = 0;
        int boundRight = col - 1;
        int boundLeft = 0;
        int boundUp = 1;
        int boundDown = row - 1;
        vector<int> result(col * row);
        int cur = 0;
        for (int i = 0; i < col * row; ++i) {
            result[cur++] = matrix[x][y];
            switch (direction) {
                case 0:
                    if (y < boundRight) {
                        ++y;
                    } else {
                        ++x;
                        --boundRight;
                        direction = (++direction) % 4;
                    }
                    break;
                case 1:
                    if (x < boundDown) {
                        ++x;
                    } else {
                        --y;
                        --boundDown;
                        direction = (++direction) % 4;
                    }
                    break;
                case 2:
                    if (y > boundLeft) {
                        --y;
                    }else{
                        --x;
                        ++boundLeft;
                        direction = (++direction) % 4;
                    }
                    break;
                case 3:
                    if(x>boundUp){
                        --x;
                    }else{
                        ++y;
                        ++boundUp;
                        direction = (++direction) % 4;
                    }
                    break;
                default :
                    break;
            }
        }
        return result;
    }
};

#endif //FH_A01_剑指_OFFER_29_H
