//
// Created by irisfeng on 2023/2/2.
//

#ifndef FH_A01_769_最多能完成排序的块_H
#define FH_A01_769_最多能完成排序的块_H

#include "../Common.h"

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int maxValue = -1;
        for(int i = 0; i < arr.size(); ++i){
            maxValue = max(maxValue, arr[i]);
            if(maxValue == i){
                ++res;
            }
        }
        return res;
    }
};

#endif //FH_A01_769_最多能完成排序的块_H
