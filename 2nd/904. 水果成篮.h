//
// Created by irisfeng on 2023/1/28.
//

#ifndef FH_A01_904_水果成篮_H
#define FH_A01_904_水果成篮_H

#include "../Common.h"

/**
 * 滑动窗口
 */

class Solution {
public:
    int totalFruit(vector<int> &fruits) {
        int n = fruits.size();
        int res = 0;
        unordered_map<int, int> fruit_num_map;
        int left = 0;
        int right = 0;
        while (right < n) {
            fruit_num_map[fruits[right]]++;
            if (fruit_num_map.size() > 2) {
                /// 更新最大值
                res = max(res, right - left);
                /// 移动窗口的左边
                while (fruit_num_map.size() > 2) {
                    fruit_num_map[fruits[left]]--;
                    if (fruit_num_map[fruits[left]] == 0) {
                        fruit_num_map.erase(fruits[left]);
                    }
                    left++;
                }
            }
            right++;
        }

        res = max(res, right - left);
        return res;
    }
};

#endif //FH_A01_904_水果成篮_H
