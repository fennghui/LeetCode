//
// Created by hpf on 22-6-28.
//

#ifndef FH_A01_剑指_OFFER_25_H
#define FH_A01_剑指_OFFER_25_H

#include "../Common.h"

//剑指 Offer 25. 合并两个排序的链表 ez
//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。


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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l1_cur = l1;
        ListNode *l2_cur = l2;
        ListNode dummyHead(0, nullptr);
        ListNode *cur = &dummyHead;
        while (l1_cur != nullptr && l2_cur != nullptr) {
            if(l1_cur->val <= l2_cur->val){
                cur->next = l1_cur;
                l1_cur = l1_cur->next;
            }else{
                cur->next = l2_cur;
                l2_cur = l2_cur->next;
            }
            cur = cur->next;
        }
        if (l1_cur != nullptr) {
            cur->next = l1_cur;
        }
        if (l2_cur != nullptr) {
            cur->next = l2_cur;
        }
        return dummyHead.next;
    }
};

#endif //FH_A01_剑指_OFFER_25_H
