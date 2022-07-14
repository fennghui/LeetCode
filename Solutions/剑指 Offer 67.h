//
// Created by irisfeng on 2022/7/14.
//

#ifndef FH_A01_剑指_OFFER_67_H
#define FH_A01_剑指_OFFER_67_H

#include "../Common.h"

//剑指 Offer 67. 把字符串转换成整数 mid
//写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。

class Solution {
public:
    int strToInt(string str) {
        if(str.length() == 0)
            return 0;
        // 去掉多余的空格
        int i = 0;
        while(str[i] == ' '){
            ++i;
        }
        str = str.substr(i, str.length() - i);

        int res = 0;
        int symbol = 1;

        if(str.length() == 0)
            return 0;
        if(str[0] == '-'){
            symbol = -1;
            str = str.substr(1, str.length() - 1);
        }else if(str[0] == '+'){
            str = str.substr(1, str.length() - 1);
        }else if(str[0] < '0' || str[0] > '9'){
            return 0;
        }

        for(i = 0; i < str.length(); ++i){
            if(str[i] < '0' || str[i] > '9')
                break;
            res *= 10;
            res += str[i] - '0';
            if(res > INT32_MAX)
                break;
        }
        if(res * symbol < INT32_MIN)
            return INT32_MIN;
        if(res * symbol > INT32_MAX)
            return INT32_MAX;
        return res * symbol;
    }
};


#endif //FH_A01_剑指_OFFER_67_H
