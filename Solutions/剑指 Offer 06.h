//
// Created by hpf on 22-6-26.
//

#ifndef FH_A01_剑指_OFFER_06_H
#define FH_A01_剑指_OFFER_06_H

#include "../Common.h"

/**
 * 剑指 Offer 06. 从尾到头打印链表
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 解法一： 队列，头插法
//    vector<int> reversePrint(ListNode* head) {
//        list<int> values;
//        int len = 0;
//        ListNode* p = head;
//        while(p != nullptr){
//            values.push_front(p->val);
//            p = p->next;
//            ++len;
//        }
//        vector<int> result(len);
//        int i = 0;
//        for(auto it = values.begin(); it != values.end(); ++it){
//            result[i++] = *it;
//        }
//        return result;
//    }

    // 解法二：栈，效率更高
    vector<int> reversePrint(ListNode* head) {
        stack<int> values;
        int len = 0;
        ListNode* p = head;
        while(p != nullptr){
            values.push(p->val);
            p = p->next;
            ++len;
        }
        vector<int> result(len);
        int i = 0;
        while(!values.empty()){
            result[i++] = values.top();
            values.pop();
        }
        return result;
    }
};

#endif //FH_A01_剑指_OFFER_06_H
