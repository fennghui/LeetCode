//
// Created by irisfeng on 2023/2/2.
//

#ifndef FH_A01_870_优势洗牌_H
#define FH_A01_870_优势洗牌_H

#include "../Common.h"

class Solution {
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        vector<int> nums2_tmp(nums2);
        sort(nums2_tmp.begin(), nums2_tmp.end());
        sort(nums1.begin(), nums1.end());
        unordered_map<int, vector<int>> nums2_nums1_map;
        int nums1_right = nums1.size() - 1;
        int nums1_left = 0;
        int nums2_right = nums2_tmp.size() - 1;
        while (nums2_right >= 0) {
            if (nums2_tmp[nums2_right] >= nums1[nums1_right]) {
                nums2_nums1_map[nums2_tmp[nums2_right]].push_back(nums1[nums1_left]);
                ++nums1_left;
                --nums2_right;
            } else {
                nums2_nums1_map[nums2_tmp[nums2_right]].push_back(nums1[nums1_right]);
                --nums1_right;
                --nums2_right;
            }
        }
        vector<int> res;
        for (int i = 0; i < nums2.size(); ++i) {
            int value = nums2_nums1_map[nums2[i]].back();
            nums2_nums1_map[nums2[i]].pop_back();
            res.push_back(value);
        }
        return res;
    }
};

#endif //FH_A01_870_优势洗牌_H
