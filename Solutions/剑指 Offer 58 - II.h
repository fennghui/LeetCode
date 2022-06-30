//
// Created by hpf on 22-6-30.
//

#ifndef FH_A01_剑指_OFFER_58_II_H
#define FH_A01_剑指_OFFER_58_II_H

#include "../Common.h"
//
//剑指 Offer 58 - II. 左旋转字符串 ez
//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
//请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(),s.end());
        reverse(s.begin(), s.begin()+(s.size()-n));
        reverse(s.begin()+(s.size()-n),s.end());
        return s;
    }
};



#endif //FH_A01_剑指_OFFER_58_II_H
