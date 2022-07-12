//
// Created by irisfeng on 2022/7/12.
//

#ifndef FH_A01_剑指_OFFER_31_H
#define FH_A01_剑指_OFFER_31_H

#include "../Common.h"

//剑指 Offer 31. 栈的压入、弹出序列 mid
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
//序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> s;
        int n = pushed.size();

        int index_pop = 0;
        for(auto &num:pushed) {
            s.push(num);
            while (index_pop < n && !s.empty() && popped[index_pop] == s.top() ) {
                s.pop();
                ++index_pop;
            }
        }
        return s.empty();
    }
};


#endif //FH_A01_剑指_OFFER_31_H
