//
// Created by hpf on 22-6-10.
//

#ifndef FH_A01_SOLUTION2269_H
#define FH_A01_SOLUTION2269_H

#include "../Common.h"

//2269. 找到一个数字的 K 美丽值 ez
//一个整数 num 的 k 美丽值定义为 num 中符合以下条件的 子字符串 数目：
//
//子字符串长度为 k 。
//子字符串能整除 num 。
//给你整数 num 和 k ，请你返回 num 的 k 美丽值。
//
//注意：
//
//允许有 前缀 0 。
//0 不能整除任何值。
//一个 子字符串 是一个字符串里的连续一段字符序列。

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        // int 转 str
        int count = 0;
        string numStr = to_string(num);
        for (int i = 0; i < numStr.size() - k + 1; ++i) {
            int sub = stoi(numStr.substr(i, k));
            if (sub != 0 && num % sub == 0) {
                ++count;
            }
        }
        return count;
    }
};

#endif //FH_A01_SOLUTION2269_H
