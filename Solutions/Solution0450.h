//
// Created by irisfeng on 2022/7/22.
//

#ifndef FH_A01_SOLUTION0450_H
#define FH_A01_SOLUTION0450_H

#include "../Common.h"

//450. 删除二叉搜索树中的节点 mid
//给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，
//并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
//
//一般来说，删除节点可分为两个步骤：
//
//首先找到需要删除的节点；
//如果找到了，删除它。

class Solution {
public:
    TreeNode *deleteOneNode(TreeNode *target){
        if(target == nullptr) return nullptr;
        if(target->right == nullptr) return target->left;
        TreeNode *cur = target->right;
        while(cur->left != nullptr)
            cur = cur->left;
        cur->left = target->left;
        return target->right;
    }
    TreeNode *deleteNode(TreeNode *root, int key) {
        TreeNode *cur = root;
        TreeNode *prev = nullptr;
        while (cur != nullptr && cur->val != key) {
            prev = cur;
            if (cur->val > key) {
                cur = cur->left;
            } else if (cur->val < key) {
                cur = cur->right;
            }
        }
        if(prev == nullptr){
            return deleteOneNode(cur);
        }

        if(prev->left != nullptr && prev->left->val == key)
            prev->left = deleteOneNode(cur);
        else if(prev->right != nullptr && prev->right->val == key)
            prev->right = deleteOneNode(cur);
        return root;
    }
};

#endif //FH_A01_SOLUTION0450_H
