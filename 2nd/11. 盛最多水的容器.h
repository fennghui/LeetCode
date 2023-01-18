//
// Created by irisfeng on 2023/1/18.
//

#ifndef FH_A01_11_盛最多水的容器_H
#define FH_A01_11_盛最多水的容器_H

#include "../Common.h"

// 双指针

// [1,3,2,5,25,24,5]

class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        if (size < 2) {
            return 0;
        }
        int max_area = 0;
        int left = 0;
        int right = size - 1;
        while (left < right) {
            // cout << "left_value " << height[left] << " right_value " << height[right] <<endl;
            int area = (right - left) * (min(height[left], height[right]));
            if (area > max_area) {
                max_area = area;
                // cout << "left " << left << " right " << right << endl;
            }
            if (left + 1 >= right) {
                break;
            }
            bool need_move_left = min(height[left], height[right]) == height[left];
            // cout << need_move_left << endl;
            if (need_move_left) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};

#endif //FH_A01_11_盛最多水的容器_H
