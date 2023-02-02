//
// Created by irisfeng on 2023/2/2.
//

#ifndef FH_A01_143_重排链表_H
#define FH_A01_143_重排链表_H

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
    void reorderList(ListNode *head) {
        unordered_map<ListNode *, ListNode *> son_father_map;
        auto right_pre = head;
        auto right = head->next;
        while(right){
            son_father_map[right] = right_pre;
            right_pre = right;
            right = right->next;
        }
        right = right_pre;
        auto left = head;
        auto left_next = left->next;
        while(left != right && son_father_map[right] != left){
            right->next = left->next;
            left_next = left->next;
            left->next = right;

            right = son_father_map[right];
            left = left_next;
        }

        right->next = nullptr;
    }
};

#endif //FH_A01_143_重排链表_H
