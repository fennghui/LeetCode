//
// Created by iris on 22-7-10.
//

#ifndef FH_A01_剑指_OFFER_36_H
#define FH_A01_剑指_OFFER_36_H

#include "../Common.h"

//剑指 Offer 36. 二叉搜索树与双向链表 mid
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *pre= nullptr;
    Node *head = nullptr;

    Node *treeToDoublyList(Node *root) {
        if(root == nullptr)
            return nullptr;
        recur(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void recur(Node *root){
        if(root == nullptr)
            return;

        recur(root->left);

        if(pre != nullptr){
            pre->right = root;
        }else{
            head = root;
        }

        root->left = pre;
        pre = root;

        recur(root->right);
    }
};

#endif //FH_A01_剑指_OFFER_36_H
