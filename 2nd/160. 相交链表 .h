//
// Created by irisfeng on 2023/2/23.
//

#ifndef FH_A01_160_相交链表_H
#define FH_A01_160_相交链表_H

#include "../Common.h"

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA) {
            ++lenA;
            curA = curA->next;
        }
        while (curB) {
            ++lenB;
            curB = curB->next;
        }
        ListNode *largeList = nullptr;
        ListNode *smallList = nullptr;
        if (lenA > lenB) {
            largeList = headA;
            smallList = headB;
        } else {
            largeList = headB;
            smallList = headA;
        }
        int k = abs(lenA - lenB);
        while (k--) {
            largeList = largeList->next;
        }
        while (largeList != smallList) {
            largeList = largeList->next;
            smallList = smallList->next;
        }
        return largeList;
    }
};

#endif //FH_A01_160_相交链表_H
