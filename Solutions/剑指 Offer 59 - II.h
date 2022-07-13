//
// Created by irisfeng on 2022/7/13.
//

#ifndef FH_A01_剑指_OFFER_59_II_H
#define FH_A01_剑指_OFFER_59_II_H

#include "../Common.h"

//剑指 Offer 59 - II. 队列的最大值 mid
//请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
//
//若队列为空，pop_front 和 max_value 需要返回 -1
// 1,4,2,5,7,3
// 1,4,5,7
// 单调双端队列

class MaxQueue {
public:
    queue<int> q;
    deque<int> q_max;

    MaxQueue() {

    }

    int max_value() {
        if (!q_max.empty()) {
            return q_max.front();
        }
        return -1;
    }

    void push_back(int value) {
        q.push(value);

        while (!q_max.empty() && value > q_max.back()) {
            q_max.pop_back();
        }
        q_max.push_back(value);

    }

    int pop_front() {
        if (!q.empty()) {
            auto front = q.front();
            if (front == q_max.front()) {
                q_max.pop_front();
            }
            q.pop();
            return front;
        }
        return -1;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

#endif //FH_A01_剑指_OFFER_59_II_H
