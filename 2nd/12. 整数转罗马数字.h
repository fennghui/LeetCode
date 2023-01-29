//
// Created by irisfeng on 2023/1/29.
//

#ifndef FH_A01_12_整数转罗马数字_H
#define FH_A01_12_整数转罗马数字_H

#include "../Common.h"

class Solution {
public:
    string intToRoman(int num) {
        static const pair<int, string> roman[] = {
                {1000, "M"},
                {900,  "CM"},
                {500,  "D"},
                {400,  "CD"},
                {100,  "C"},
                {90,   "XC"},
                {50,   "L"},
                {40,   "XL"},
                {10,   "X"},
                {9,    "IX"},
                {5,    "V"},
                {4,    "IV"},
                {1,    "I"},
        };
        string res;
        for (auto &[value, romanStr]: roman) {
            while (num >= value) {
                res += romanStr;
                num -= value;
            }
            if(num==0){
                break;
            }
        }
        return res;
    }
};

#endif //FH_A01_12_整数转罗马数字_H
