//
// Created by irisfeng on 2022/7/12.
//

#ifndef FH_A01_剑指_OFFER_66_H
#define FH_A01_剑指_OFFER_66_H

#include "../Common.h"

//剑指 Offer 66. 构建乘积数组 mid
//给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
//其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积,
//即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

class Solution {
public:
    vector<int> constructArr(vector<int> &a) {
        int n = a.size();
        if(n == 0)
            return {};
        vector<int> front(n, 0), end(n, 0);
        front[0] = 1;
        end[n-1] = 1;
        for (int i = 1; i < n; ++i) {
            front[i] = front[i-1] * a[i-1];
        }
        for (int i = n - 2; i >= 0; --i) {
            end[i] = end[i+1] * a[i+1];
        }
        vector<int> b(n, 0);
        for (int i = 0; i < n; ++i) {
            b[i] = front[i] * end[i];
        }
        return b;
    }
};

#endif //FH_A01_剑指_OFFER_66_H
