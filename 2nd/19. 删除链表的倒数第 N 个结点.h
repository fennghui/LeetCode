//
// Created by irisfeng on 2023/2/2.
//

#ifndef FH_A01_19_删除链表的倒数第_N_个结点_H
#define FH_A01_19_删除链表的倒数第_N_个结点_H

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
 *
 * [](slow) -> 1(fast)
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto newHead = new ListNode(0,head);
        auto slow = newHead;
        auto fast = newHead;
        while(n--){
            fast = fast->next;
        }
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return newHead->next;
    }
};

#endif //FH_A01_19_删除链表的倒数第_N_个结点_H
