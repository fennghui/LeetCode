//
// Created by irisfeng on 2023/1/30.
//

#ifndef FH_A01_179_最大数_H
#define FH_A01_179_最大数_H

#include "../Common.h"

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> numsStr(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            numsStr[i] = to_string(nums[i]);
        }
        sort(numsStr.begin(), numsStr.end(), [](string &a, string &b) {
            return (a + b) > (b + a);
        });
        string res;
        for (auto &str: numsStr) {
            res += str;
        }
        /// 特殊处理 去掉多余的 0
        int resLen = res.size();
        int i = 0;
        while (i < resLen) {
            if (res[i] != '0') {
                break;
            }
            ++i;
        }
        return (i == 0) ? res : res.substr(i - 1, resLen - (i - 1));
    }
};

#endif //FH_A01_179_最大数_H
