//
// Created by irisfeng on 2023/2/20.
//

#ifndef FH_A01_901_股票价格跨度_H
#define FH_A01_901_股票价格跨度_H

#include "../Common.h"

/**
 * 使用单调栈
 * 内存消耗变小了
 */
class StockSpanner {
public:
    StockSpanner() {
    }

    int next(int price) {
        int span = 1;
        while (!ss.empty() && ss.top().second <= price) {
            span += ss.top().first;
            ss.pop();
        }
        ss.push({span, price});
        return span;
    }

private:
    stack<pair<int, int>> ss; /// span, price
};


/**
 * 没有用单调栈的方法
 */
class StockSpanner_1 {
public:
    vector<int> prices;
    vector<int> spans;
    int size;

    StockSpanner_1() : size(0) {
    }

    int next(int price) {
        if (size == 0 || price < prices[size - 1]) {
            prices.push_back(price);
            spans.push_back(1);
            ++size;
            return 1;
        }

        int p = size - 1;
        int span = 1; /// 初始为自己
        while (p >= 0 && prices[p] <= price) {
            span += spans[p];
            p -= spans[p];
        }
        prices.push_back(price);
        spans.push_back(span);
        ++size;
        return span;
    }
};



/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

#endif //FH_A01_901_股票价格跨度_H
