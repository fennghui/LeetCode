//
// Created by irisfeng on 2023/1/19.
//

#ifndef FH_A01_22_括号生成_H
#define FH_A01_22_括号生成_H

#include "../Common.h"

class Solution {
public:
    vector<string> res;
    string path;

    vector<string> generateParenthesis(int n) {
        if (n < 1) {
            return res;
        }
        backTracing(n, 0, 0);
        return res;
    }

    void backTracing(int n, int left_num, int right_num) {
        if (left_num == n && right_num == n) {
            res.push_back(path);
            return;
        }
        if (left_num == right_num) {
            path.push_back('(');
            backTracing(n, left_num + 1, right_num);
            path.pop_back();
        }else if(left_num > right_num){
            // 可以放左括号
            if(left_num < n){
                path.push_back('(');
                backTracing(n,left_num+1,right_num);
                path.pop_back();
            }
            // 可以放右括号
            path.push_back(')');
            backTracing(n, left_num,right_num+1);
            path.pop_back();
        }
    }

};

#endif //FH_A01_22_括号生成_H
