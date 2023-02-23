//
// Created by irisfeng on 2023/2/23.
//

#ifndef FH_A01_206_反转链表_H
#define FH_A01_206_反转链表_H

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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode *newHead = new ListNode(-1, head);
        ListNode *pre = head;
        ListNode *cur = head->next;
        while(cur != nullptr){
            pre->next = cur->next;
            cur->next = newHead->next;
            newHead->next = cur;
            cur = pre->next;
        }

        return newHead->next;
    }
};

#endif //FH_A01_206_反转链表_H
