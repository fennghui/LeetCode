//
// Created by irisfeng on 2023/2/22.
//

#ifndef FH_A01_946_验证栈序列_H
#define FH_A01_946_验证栈序列_H

#include "../Common.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> myStack;
        int poppedIndex = 0;
        for(int i = 0; i < pushed.size(); ++i){
            myStack.push(pushed[i]);
            while(!myStack.empty() && myStack.top() == popped[poppedIndex]){
                myStack.pop();
                ++poppedIndex;
            }
        }

        while(!myStack.empty() && poppedIndex < popped.size()){
            if(popped[poppedIndex] == myStack.top()){
                myStack.pop();
                ++poppedIndex;
            }else{
                return false;
            }
        }

        return true;
    }
};

#endif //FH_A01_946_验证栈序列_H
