//
// Created by hpf on 22-6-28.
//

#ifndef FH_A01_剑指_OFFER_30_H
#define FH_A01_剑指_OFFER_30_H

#include "../Common.h"

//剑指 Offer 30. 包含min函数的栈
//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

class MinStack {
    stack<int> myStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        myStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        auto top = myStack.top();
        myStack.pop();
        if (!minStack.empty() && top == minStack.top()) {
            minStack.pop();
        }
    }

    int top() {
        return myStack.top();
    }

    int min() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

#endif //FH_A01_剑指_OFFER_30_H
