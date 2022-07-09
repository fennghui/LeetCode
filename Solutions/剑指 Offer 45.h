//
// Created by iris on 22-7-9.
//

#ifndef FH_A01_剑指_OFFER_45_H
#define FH_A01_剑指_OFFER_45_H

#include "../Common.h"

//剑指 Offer 45. 把数组排成最小的数 mid
//输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

/**
 * 排序判断规则：
 * 若 x || y > y || x，则 x > y
 * 若 x || y < y || x，则 x < y
 */
class Solution {
public:
    static bool compare(const string &x, const string &y) {
        return x + y < y + x;
    }

    string minNumber(vector<int> &nums) {
        int n = nums.size();
        vector<string> nums_str(n);
        int i = 0;
        for (const auto &num: nums) {
            nums_str[i++] = to_string(num);
        }
        string res = "";
        sort(nums_str.begin(), nums_str.end(), compare);
        for(const auto &str : nums_str){
            res += str;
        }
        return res;
    }

};

#endif //FH_A01_剑指_OFFER_45_H
