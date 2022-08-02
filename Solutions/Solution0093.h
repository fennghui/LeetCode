//
// Created by irisfeng on 2022/8/2.
//

#ifndef FH_A01_SOLUTION0093_H
#define FH_A01_SOLUTION0093_H

#include "../Common.h"

//93. 复原 IP 地址 mid
//有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
//
//例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
//给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

class Solution {
public:
    vector<string> res;
    vector<string> path;

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return res;
        backtracking(s, 0);
        return res;
    }

    void backtracking(string &s, int startIndex) {
        if (startIndex >= s.size() || path.size() >= 4) {
            if (startIndex == s.size() && path.size() == 4) {
                string ipStr = path[0];
                for (int i = 1; i < path.size(); i++) {
                    ipStr += '.';
                    ipStr += path[i];
                }
                res.push_back(ipStr);
            }
            return;
        }

        for (int i = startIndex; i < s.size() && i <= startIndex + 2; ++i) {
            string ipStr = s.substr(startIndex, i - startIndex + 1);
            if (isValid(s, startIndex, i)){
                path.push_back(ipStr);
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }

    bool isValid(string &s, int left, int right) {
        if (left > right || right - left > 2)
            return false;
        if (s[left] == '0' && left != right) {
            return false;
        }
        int num = 0;
        for(int i = left; i <= right; ++i){
            if(s[i] < '0' || s[i] > '9')
                return false;
            num = num * 10 + s[i] - '0';
            if(num > 255)
                return false;
        }
        return true;
    }
};

#endif //FH_A01_SOLUTION0093_H
