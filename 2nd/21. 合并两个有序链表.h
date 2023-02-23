//
// Created by irisfeng on 2023/2/23.
//

#ifndef FH_A01_21_合并两个有序链表_H
#define FH_A01_21_合并两个有序链表_H

#include "../Common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *newHead = new ListNode(-1);
        ListNode *pre = newHead;
        while (list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val){
                pre->next = list1;
                list1 = list1->next;
            }else{
                pre->next = list2;
                list2 = list2->next;
            }
            pre = pre->next;
        }
        pre->next = list1 != nullptr ? list1 : list2;
        return newHead->next;
    }
};

#endif //FH_A01_21_合并两个有序链表_H
