//
// Created by irisfeng on 2022/7/13.
//

#ifndef FH_A01_剑指_OFFER_59_I_H
#define FH_A01_剑指_OFFER_59_I_H

#include "../Common.h"

//剑指 Offer 59 - I. 滑动窗口的最大值 hard
//给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

//单调双端队列

class Solution {
public:
    deque<int> deq;

    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deq.clear();
        if(nums.size() == 0)
            return {};

        for (int i = 0; i < k; ++i) {
            push(nums[i]);
        }
        vector<int> res;
        res.push_back(deq.front());
        for (int i = k, j = 0; i < nums.size(); ++i, ++j) {
            pop(nums[j]);
            push(nums[i]);
            res.push_back(deq.front());
        }
        return res;
    }

    void push(int &value) {
        while (!deq.empty() && value > deq.back()) {
            deq.pop_back();
        }
        deq.push_back(value);
    }

    void pop(int &value) {
        if (!deq.empty() && value == deq.front()) {
            deq.pop_front();
        }
    }

};

#endif //FH_A01_剑指_OFFER_59_I_H
