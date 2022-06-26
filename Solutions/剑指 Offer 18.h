//
// Created by hpf on 22-6-26.
//

#ifndef FH_A01_剑指_OFFER_18_H
#define FH_A01_剑指_OFFER_18_H

#include "../Common.h"

//剑指 Offer 18. 删除链表的节点
//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
//
//返回删除后的链表的头节点。
//
//注意：此题对比原题有改动

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
    ListNode* deleteNode(ListNode* head, int val) {
        // 添加一个头结点
        ListNode* newHead = new ListNode();
        newHead->next = head;
        ListNode* pre = newHead;
        ListNode* cur = head;
        while(cur != nullptr){
            if(cur->val == val){
                pre->next = cur->next;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        head = newHead->next;
        delete newHead;
        return head;
    }
};



#endif //FH_A01_剑指_OFFER_18_H
