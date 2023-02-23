//
// Created by irisfeng on 2023/2/23.
//

#ifndef FH_A01_141_环形链表_H
#define FH_A01_141_环形链表_H

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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow && fast){
            slow = slow->next;
            if(fast->next){
                fast = fast->next->next;
                if(slow == fast){
                    return true;
                }
            }else{
                return false;
            }
        }
        return false;
    }
};

#endif //FH_A01_141_环形链表_H
