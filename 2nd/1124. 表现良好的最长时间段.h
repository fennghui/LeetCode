//
// Created by irisfeng on 2023/1/29.
//

#ifndef FH_A01_1124_表现良好的最长时间段_H
#define FH_A01_1124_表现良好的最长时间段_H

#include "../Common.h"

/**
 * 单调栈
 */

class Solution {
public:
    int longestWPI(vector<int> &hours) {
        int n = hours.size();
        vector<int> preSum(n + 1, 0);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += (hours[i - 1] - 8) > 0 ? 1 : -1;
            preSum[i] = sum;
            cout << "preSum " << i << " " << preSum[i] << endl;
        }
        int longest = 0;
        /**
         * 暴力解法：超出时间限制
         */
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 0; j < i; ++j) {
//                if (preSum[i] - preSum[j] > 0) {
//                    longest = max(longest, i - j);
//                    break;
//                }
//            }
//        }
        /**
         * 单调栈：维护单调递减序列
         */
        stack<int> myStack;
        myStack.push(0);
        for (int i = 1; i <= n; ++i) {
            if (preSum[i] < preSum[myStack.top()]) {
                myStack.push(i);
                cout << "i " << i << endl;
            }
        }
        for (int i = n; i >= 0 && !myStack.empty(); --i) {
            while (!myStack.empty() && (preSum[i] - preSum[myStack.top()]) > 0) {
                //cout << "top " << top << endl;
                longest = max(longest, i - myStack.top());
                myStack.pop();

            }
        }

        return longest;
    }

};

#endif //FH_A01_1124_表现良好的最长时间段_H
