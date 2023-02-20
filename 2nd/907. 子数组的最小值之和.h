//
// Created by irisfeng on 2023/2/20.
//

#ifndef FH_A01_907_子数组的最小值之和_H
#define FH_A01_907_子数组的最小值之和_H

#include "../Common.h"

/**
 * 单调栈
 */

class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> dp(n, 0);/// 以 arr[i]结尾的子数组的最小值之和
        stack<int> monoStack; /// 单调栈里面存的是索引
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            while (!monoStack.empty() && arr[monoStack.top()] > arr[i]) {
                monoStack.pop();
            }
            int k = monoStack.empty() ? i + 1 : i - monoStack.top();
//            cout << "k " << k << " ";
            dp[i] = (monoStack.empty() ? 0 : dp[i - k]) + k * arr[i];
//            cout << "dp[i] " << dp[i] << endl;
            monoStack.push(i);
            sum += dp[i];
        }

        return sum % (int) (1e9 + 7);
    }
};

#endif //FH_A01_907_子数组的最小值之和_H
