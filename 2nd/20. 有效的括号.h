//
// Created by irisfeng on 2023/2/23.
//

#ifndef FH_A01_20_有效的括号_H
#define FH_A01_20_有效的括号_H

#include "../Common.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        int index = 0;
        while (index < s.size()) {
            if (s[index] == '(' || s[index] == '{' || s[index] == '[') {
                myStack.emplace(s[index]);
            } else if (!myStack.empty()) {
                auto top = myStack.top();
                if ((s[index] == ')' && top == '(') || (s[index] == '}' && top == '{') ||
                    (s[index] == ']' && top == '[')) {
                    myStack.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
            ++index;
        }
        return myStack.empty();
    }
};

#endif //FH_A01_20_有效的括号_H
