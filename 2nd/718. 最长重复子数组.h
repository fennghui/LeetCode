//
// Created by irisfeng on 2023/2/20.
//

#ifndef FH_A01_718_最长重复子数组_H
#define FH_A01_718_最长重复子数组_H

#include "../Common.h"

class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(res, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }
};

#endif //FH_A01_718_最长重复子数组_H
