//
// Created by iris on 22-7-11.
//

#ifndef FH_A01_剑指_OFFER_64_H
#define FH_A01_剑指_OFFER_64_H

#include "../Common.h"

//剑指 Offer 64. 求1+2+…+n mid
//求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

class Solution {
public:
    int sumNums(int n) {
        // 递归
        n && (n += sumNums(n - 1));
        return n;
    }
};


#endif //FH_A01_剑指_OFFER_64_Hfe
