//
// Created by hpf on 22-6-30.
//

#ifndef FH_A01_剑指_OFFER_62_H
#define FH_A01_剑指_OFFER_62_H

#include "../Common.h"

//剑指 Offer 62. 圆圈中最后剩下的数字 ez
//0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。
//
//例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 1)
            return 0;
        vector<int> result(n+1);
        result[1] = 0;
        for (int i = 2; i <= n; i++) {
            result[i] = (result[i - 1] + m) % i;
        }
        return result[n];
    }
};

#endif //FH_A01_剑指_OFFER_62_H
