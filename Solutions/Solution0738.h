//
// Created by irisfeng on 2022/8/8.
//

#ifndef FH_A01_SOLUTION0738_H
#define FH_A01_SOLUTION0738_H

#include "../Common.h"

//738. 单调递增的数字 mid
//当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
//
//给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        // 直接转为 string 方便操作
//        vector<int> bits;
//        while (n != 0) {
//            bits.push_back(n % 10);
//            n = n / 10;
//        }
        string strN = to_string(n);
        int flag = strN.size();
        for(int i = strN.size()-1; i > 0 ; --i){
            if(strN[i] < strN[i-1]){
                strN[i-1]--;
                flag = i;
            }
        }
        for(int i = flag; i < strN.size(); ++i){
            strN[i] = '9';
        }
        return stoi(strN);
//        for (int i = bits.size() - 1; i > 0; --i) {
//            if (bits[i] > bits[i - 1]) {
//                int j;
//                for (j = i; j < bits.size() && bits[j] == bits[i]; ++j);
//                bits[j - 1]--;
//                for (int k = j - 2; k >= 0; --k)
//                    bits[k] = 9;
//            }
//        }

//        int res = 0;
//        for (int i = bits.size() - 1; i >= 0; --i) {
//            res = res * 10 + bits[i];
//        }
//        return res;
    }
};

#endif //FH_A01_SOLUTION0738_H
