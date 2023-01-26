//
// Created by irisfeng on 2023/1/26.
//

#ifndef FH_A01_670_最大交换_H
#define FH_A01_670_最大交换_H

#include "../Common.h"

class Solution {
public:
    int maximumSwap(int num) {
        string num_str = to_string(num);
        string tmp_str(num_str);
        sort(tmp_str.begin(), tmp_str.end(), [](char a, char b) { return a > b; });

        int left = -1;
        for (int i = 0; i < num_str.size(); i++) {
            if (num_str[i] != tmp_str[i]) {
                left = i;
                break;
            }
        }
        if (left == -1) {
            return num;
        }


        for (int i = num_str.size() - 1; i >= left + 1; i--) {
            if (num_str[i] == tmp_str[left]) {
                swap(num_str[i], num_str[left]);
                break;
            }
        }

        return stoi(num_str);
    }
};

#endif //FH_A01_670_最大交换_H
