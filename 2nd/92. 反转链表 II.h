//
// Created by irisfeng on 2023/1/27.
//

#ifndef FH_A01_92_反转链表_II_H
#define FH_A01_92_反转链表_II_H

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


ListNode *reverseBetween(ListNode *head, int left, int right) {
    // 设置 dummyNode 是这一类问题的一般做法
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *pre = dummyNode;
    for (int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }
    ListNode *cur = pre->next;
    ListNode *next;
    for (int i = 0; i < right - left; i++) {
        next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummyNode->next;
}


class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == right) {
            return head;
        }
        /// 新的头结点，方便处理
        ListNode *new_head = new ListNode(-1);
        new_head->next = head;
        /// 遍历需要的变量
        ListNode *pre = new_head;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *next = nullptr;
        /// 每次操作的是 next， cur 当做 pre
        for (int i = left; i < right; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return new_head->next;
    }
};

#endif //FH_A01_92_反转链表_II_H
