//
// Created by irisfeng on 2023/1/16.
//

#ifndef FH_A01_2_两数相加_H
#define FH_A01_2_两数相加_H

#include "../Common.h"

//2. 两数相加
//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode;
        int flag = 0;
        ListNode *pre = head;
        while (l1 != nullptr && l2 != nullptr) {
            pre->next = new ListNode;
            int add_val = l1->val + l2->val + flag;
            if (add_val < 10) {
                pre->next->val = add_val;
                flag = 0;
            } else {
                pre->next->val = add_val - 10;
                flag = 1;
            }
            l1 = l1->next;
            l2 = l2->next;
            pre = pre->next;
        }

        ListNode *ll = (l1 != nullptr) ? l1 : l2;
        while (ll != nullptr) {
            pre->next = new ListNode;
            int add_val = ll->val + flag;
            if (add_val < 10) {
                pre->next->val = add_val;
                flag = 0;
            } else {
                pre->next->val = add_val - 10;
                flag = 1;
            }
            ll = ll->next;
            pre = pre->next;
        }

        if(flag != 0){
            pre->next = new ListNode(flag);
        }

        return head->next;
    }
};



#endif //FH_A01_2_两数相加_H
