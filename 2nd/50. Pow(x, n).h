//
// Created by irisfeng on 2023/2/19.
//

#ifndef FH_A01_50_POW_X_N_H
#define FH_A01_50_POW_X_N_H

#include "../Common.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1) return x;
        if (n == -1) return 1 / x;
        if (n == 0)return 1;
        double powHalf = myPow(x, n / 2);
        return ((n & 0x1) == 0x1) ? ((n < 0) ? powHalf * powHalf * 1 / x : powHalf * powHalf * x) :
               powHalf * powHalf;
    }
};

#endif //FH_A01_50_POW_X_N_H
