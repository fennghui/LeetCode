//
// Created by hpf on 22-7-1.
//

#ifndef FH_A01_剑指_OFFER_04_H
#define FH_A01_剑指_OFFER_04_H

#include "../Common.h"

//剑指 Offer 04. 二维数组中的查找 mid
//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int row = matrix.size() -  1;
        int col = matrix[0].size() -1;
        int i = 0, j = col;
        while(i <= row && j >=0){
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j]  < target){
                ++i;
            }else{
                --j;
            }
        }
        return false;
    }
};

#endif //FH_A01_剑指_OFFER_04_H
