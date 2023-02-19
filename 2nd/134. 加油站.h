//
// Created by irisfeng on 2023/2/19.
//

#ifndef FH_A01_134_加油站_H
#define FH_A01_134_加油站_H

#include "../Common.h"

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int totalSum = 0;
        int curSum = 0;
        int start = 0;
        for(int i = 0; i < n; ++i){
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0){
                start = i + 1;
                curSum = 0;
            }
        }
        if(totalSum < 0) return -1;
        return start;
    }
};

#endif //FH_A01_134_加油站_H
