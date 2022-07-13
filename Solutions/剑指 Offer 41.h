//
// Created by irisfeng on 2022/7/13.
//

#ifndef FH_A01_剑指_OFFER_41_H
#define FH_A01_剑指_OFFER_41_H

#include "../Common.h"

//剑指 Offer 41. 数据流中的中位数 hard
//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
//如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
//
//例如，
//
//[2,3,4] 的中位数是 3
//
//[2,3] 的中位数是 (2 + 3) / 2 = 2.5
//
//设计一个支持以下两种操作的数据结构：
//
//void addNum(int num) - 从数据流中添加一个整数到数据结构中。
//double findMedian() - 返回目前所有元素的中位数。

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<> > bigHeap;
    int bigN;
    priority_queue<int> smallHeap;
    int smallN;


    MedianFinder() {
        bigN = 0;
        smallN = 0;
    }

    void addNum(int num) {
        if (bigN == smallN) {
            smallHeap.push(num);
            auto top = smallHeap.top();
            smallHeap.pop();
            bigHeap.push(top);
            ++bigN;
            return;
        }
        if (bigN > smallN) {
            bigHeap.push(num);
            auto top = bigHeap.top();
            bigHeap.pop();
            smallHeap.push(top);
            ++smallN;
            return;
        }
    }

    double findMedian() {
        return (bigN == smallN) ? (bigHeap.top() + smallHeap.top()) / 2.0 : bigHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#endif //FH_A01_剑指_OFFER_41_H
