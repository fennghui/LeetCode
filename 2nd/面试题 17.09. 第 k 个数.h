//
// Created by irisfeng on 2023/1/20.
//

#ifndef FH_A01_面试题_17_09_第_K_个数_H
#define FH_A01_面试题_17_09_第_K_个数_H

#include "../Common.h"

// 回溯

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> dp(k + 1);
        dp[1] = 1;
        int p3, p5, p7;
        p3 = p5 = p7 = 1;
        for(int i = 2; i <= k; i++){
            dp[i] = min(min(dp[p3]*3, dp[p5]*5), dp[p7]*7);
            if(dp[p3]*3 == dp[i]){
                p3++;
            }
            if(dp[p5]*5 == dp[i]){
                p5++;
            }
            if(dp[p7]*7 == dp[i]){
                p7++;
            }
        }
        return dp[k];
    }
};

#endif //FH_A01_面试题_17_09_第_K_个数_H
