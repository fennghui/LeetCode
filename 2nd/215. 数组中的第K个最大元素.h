//
// Created by irisfeng on 2023/1/26.
//

#ifndef FH_A01_215_数组中的第K个最大元素_H
#define FH_A01_215_数组中的第K个最大元素_H

#include "../Common.h"

class Solution {
public:
    /**
     * 自己实现堆排序
     */
    int findKthLargest(vector<int>& nums, int k) {

    }
};

/**
 * STL 实现
 */
//int findKthLargest(vector<int>& nums, int k) {
//    priority_queue<int> big_heap;
//    for(auto &num:nums){
//        big_heap.push(num);
//    }
//    for(int i=0;i<k-1;i++){
//        big_heap.pop();
//    }
//
//    return big_heap.top();
//}

#endif //FH_A01_215_数组中的第K个最大元素_H
