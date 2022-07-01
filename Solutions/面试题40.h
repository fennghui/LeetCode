//
// Created by hpf on 22-7-1.
//

#ifndef FH_A01_面试题40_H
#define FH_A01_面试题40_H

#include "../Common.h"
//面试题40. 最小的k个数 ez
//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        if(k == 0)
            return {};
        int n = arr.size();
        int cnt = 0;
        priority_queue<int,vector<int>> bigHeap;
        for (const auto &num: arr) {
            if (k != 0){
                bigHeap.push(num);
                --k;
            }else{
                auto head = bigHeap.top();
                if(num <head){
                    bigHeap.pop();
                    bigHeap.push(num);
                }
            }
        }
        vector<int> res;
        while(!bigHeap.empty()){
            res.push_back(bigHeap.top());
            bigHeap.pop();
        }
        return res;
    }
};

#endif //FH_A01_面试题40_H
