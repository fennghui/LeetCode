//
// Created by irisfeng on 2023/1/28.
//

#ifndef FH_A01_剑指_OFFER_46_把数字翻译成字符串_H
#define FH_A01_剑指_OFFER_46_把数字翻译成字符串_H

#include "../Common.h"

class Solution {
public:
    int res = 0;

    int translateNum(int num) {
        string numStr = to_string(num);
        backTracking(numStr, numStr.size(), 0);
        return res;
    }

    void backTracking(string &numStr, int strLen, int curIndex) {
        if (curIndex >= strLen) {
            res++;
            return;
        }

        /// 读一位
        backTracking(numStr, strLen, curIndex + 1);
        /// 读两位
        if(curIndex + 2 <= strLen){
            int num = 0;
            for(int i = curIndex; i < curIndex + 2; i++){
                num = num * 10 + numStr[i] - '0';
            }
            if(num <= 25 && num >= 10){
                backTracking(numStr, strLen, curIndex + 2);
            }
        }
    }
};

#endif //FH_A01_剑指_OFFER_46_把数字翻译成字符串_H
