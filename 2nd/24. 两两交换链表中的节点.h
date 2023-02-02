//
// Created by irisfeng on 2023/2/2.
//

#ifndef FH_A01_24_两两交换链表中的节点_H
#define FH_A01_24_两两交换链表中的节点_H

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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        auto newHead = new ListNode(0,head);
        auto pre = newHead;
        auto slow = newHead->next;
        auto fast = slow->next;
        while(slow && fast){
            pre->next = fast;
            slow->next = fast->next;
            fast->next = slow;
            pre = slow;

            slow = slow->next;
            fast = slow ? slow->next : nullptr;
        }
        return newHead->next;
    }
};

#endif //FH_A01_24_两两交换链表中的节点_H
