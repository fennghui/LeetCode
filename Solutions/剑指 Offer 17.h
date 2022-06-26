//
// Created by hpf on 22-6-26.
//

#ifndef FH_A01_剑指_OFFER_17_H
#define FH_A01_剑指_OFFER_17_H

#include "../Common.h"

//剑指 Offer 17. 打印从1到最大的n位数
//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> result;
        int start = 1;
        for (int i = 0; i < pow(10, n) - 1; ++i) {
            result.push_back(start++);
        }
        return result;
    }
};


#endif //FH_A01_剑指_OFFER_17_H
