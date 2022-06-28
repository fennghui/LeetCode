//
// Created by hpf on 22-6-28.
//

#ifndef FH_A01_剑指_OFFER_52_H
#define FH_A01_剑指_OFFER_52_H

#include "../Common.h"

//剑指 Offer 52. 两个链表的第一个公共节点 ez
//输入两个链表，找出它们的第一个公共节点。

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
        int lenA = 0, lenB = 0;
        ListNode *A = headA;
        ListNode *B = headB;
        while (A != nullptr) {
            ++lenA;
            A = A->next;
        }
        while (B != nullptr) {
            ++lenB;
            B = B->next;
        }
        int shortLen = (lenA > lenB) ? lenB : lenA;
        ListNode *longList = (lenA > lenB) ? headA : headB;
        ListNode *shortList = (lenA > lenB) ? headB : headA;
        int iterLen = (lenA > lenB) ? lenA - lenB : lenB - lenA;
        for (int i = 0; i < iterLen; i++) {
            longList = longList->next;
        }
        for (int i = 0; i < shortLen; ++i) {
            if (longList == shortList){
                return longList;
            }else{
                longList = longList->next;
                shortList = shortList->next;
            }
        }
        return nullptr;
    }
};

#endif //FH_A01_剑指_OFFER_52_H
