//
// Created by irisfeng on 2023/1/29.
//

#ifndef FH_A01_707_设计链表_H
#define FH_A01_707_设计链表_H

#include "../Common.h"

class MyLinkedListNode {
public:
    MyLinkedListNode() : val(0), next(nullptr) {}

    MyLinkedListNode(int valParam) : val(valParam), next(nullptr) {}

    MyLinkedListNode(int valParam, MyLinkedListNode *nextParam) : val(valParam), next(nextParam) {}

    int val;
    MyLinkedListNode *next;
};

class MyLinkedList {
public:
    MyLinkedList() {
        myList = new MyLinkedListNode();
    }

    int get(int index) {
        // cout<<"get "<<index<<endl;
        if (index < 0) {
            return -1;
        }
        MyLinkedListNode *cur = myList;
        while (index >= 0 && cur != nullptr) {
            cur = cur->next;
            --index;
        }
        return cur == nullptr ? -1 : cur->val;
    }

    void addAtHead(int val) {
        // cout<<"addAtHead "<<val<<endl;
        MyLinkedListNode *head = new MyLinkedListNode(val, myList->next);
        myList->next = head;
    }

    void addAtTail(int val) {
        // cout<<"addAtTail "<<val<<endl;
        MyLinkedListNode *cur = myList;
        MyLinkedListNode *pre = nullptr;
        while (cur != nullptr) {
            pre = cur;
            cur = cur->next;
        }
        MyLinkedListNode *tail = new MyLinkedListNode(val);
        pre->next = tail;
    }

    void addAtIndex(int index, int val) {
        // cout<<"addAtIndex "<<index<<" "<<val<<endl;
        if (index < 0) {
            addAtHead(val);
        }
        MyLinkedListNode *cur = myList;
        MyLinkedListNode *pre = nullptr;
        while (index >= 0 && cur != nullptr) {
            pre = cur;
            cur = cur->next;
            --index;
        }
        MyLinkedListNode *newNode = new MyLinkedListNode(val);
        if (cur == nullptr && index == -1) { /// 添加在尾部
            pre->next = newNode;
        } else if (cur != nullptr) {
            newNode->next = pre->next;
            pre->next = newNode;
        } else {
            /// 如果 index 大于链表长度，则不会插入节点。
        }
    }

    void deleteAtIndex(int index) {
        // cout<<"deleteAtIndex "<<index<<endl;
        if (index < 0) {
            return;
        }
        MyLinkedListNode *cur = myList;
        MyLinkedListNode *pre = nullptr;
        while (index >= 0 && cur != nullptr) {
            pre = cur;
            cur = cur->next;
            --index;
        }
        if (cur != nullptr) {
            pre->next = cur->next;
        }
    }

private:
    MyLinkedListNode *myList; /// 有一个头指针
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

#endif //FH_A01_707_设计链表_H
