//
// Created by hpf on 22-6-26.
//

#ifndef FH_A01_剑指_OFFER_09_H
#define FH_A01_剑指_OFFER_09_H

#include "../Common.h"

// 剑指 Offer 09. 用两个栈实现队列
// 用两个栈实现一个队列。
// 队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
// 分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
//

class CQueue {
public:
    stack<int> inStack;
    stack<int> outStack;

    CQueue() {
    }

    void appendTail(int value) {
        while(!outStack.empty()){
            auto top = outStack.top();
            outStack.pop();
            inStack.push(top);
        }
        inStack.push(value);
    }

    int deleteHead() {
        while(!inStack.empty()){
            auto top = inStack.top();
            inStack.pop();
            outStack.push(top);
        }
        if(!outStack.empty()){
            auto top = outStack.top();
            outStack.pop();
            return top;
        }

        return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */


#endif //FH_A01_剑指_OFFER_09_H
