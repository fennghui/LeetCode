//
// Created by hpf on 22-6-26.
//

#ifndef FH_A01_剑指_OFFER_05_H
#define FH_A01_剑指_OFFER_05_H

#include "../Common.h"
/**
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."

 */

class Solution {
public:
    string replaceSpace(string s) {
        string result;
        for(auto &c : s){
            if(c == ' '){
                result += "%20";
            }else {
                result += c;
            }
        }
        return result;
    }
};

#endif //FH_A01_剑指_OFFER_05_H
