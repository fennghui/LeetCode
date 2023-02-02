//
// Created by irisfeng on 2023/1/31.
//

#ifndef FH_A01_148_排序链表_H
#define FH_A01_148_排序链表_H

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

/**
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序
 */

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *newHead = new ListNode(0, head);
        /// 实现归并排序
        /// 1. 划分为两部分，分别对每部分进行排序
        /// 2. 递归版是从宏观到微观，这里要用自底向上的方法，保证 O(1) 的空间复杂度
        int length = 0;
        auto p = head;
        while (p) {
            ++length;
            p = p->next;
        }

        for (int step = 1; step < length; step <<= 1) {
            auto cur = newHead->next;
            auto tail = newHead;

            while(cur){
                auto left = cur;
                auto right = cut(left, step);
                cur = cut(right,step);
                tail->next = merge(left, right);
                while(tail->next){
                    tail = tail->next;
                }
            }
        }

        return newHead->next;
    }

    /// @brief 双路归并
    ListNode *merge(ListNode *l1, ListNode *l2) {
        auto newHead = new ListNode(0);
        auto curP = newHead;

        while(l1 && l2){
            if(l1->val < l2->val){
                curP->next = l1;
                l1 = l1->next;
            }else{
                curP->next = l2;
                l2 = l2->next;
            }
            curP = curP->next;
        }
        curP->next = l1 ? l1 : l2;

        return newHead->next;
    }

    /// @brief 将链表 l 切掉前 n 个节点，并返回后半部分的链表头
    ListNode *cut(ListNode *l, int n) {
        auto p = l;
        while(--n && p){
            p = p->next;
        }
        if(!p){
            return nullptr;
        }
        auto next = p->next;
        p->next = nullptr;
        return next;
    }
};

#endif //FH_A01_148_排序链表_H
