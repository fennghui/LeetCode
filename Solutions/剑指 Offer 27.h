//
// Created by hpf on 22-6-28.
//

#ifndef FH_A01_剑指_OFFER_27_H
#define FH_A01_剑指_OFFER_27_H

#include "../Common.h"

//剑指 Offer 27. 二叉树的镜像
//请完成一个函数，输入一个二叉树，该函数输出它的镜像。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * 1. 先序遍历的迭代版本
 * 2. 翻转之后是镜像树的先序遍历
 * 3. 对树序列化
 */
class Solution {
public:
    // 方法一：递归做法好简单
//    TreeNode *mirrorTree(TreeNode *root) {
//        if (root == nullptr)
//            return root;
//        TreeNode *left = mirrorTree(root->left);
//        TreeNode *right = mirrorTree(root->right);
//        root->left = right;
//        root->right = left;
//        return root;
//    }
    // 方法二：使用栈来辅助
    TreeNode *mirrorTree(TreeNode *root) {
        if (root == nullptr)
            return root;
        stack<TreeNode *> assistStack;
        assistStack.push(root);
        while(!assistStack.empty()){
            auto curr = assistStack.top();
            assistStack.pop();
            if(curr->left)
                assistStack.push(curr->left);
            if(curr->right)
                assistStack.push(curr->right);
            swap(curr->left, curr->right);
        }
        return root;
    }

};

#endif //FH_A01_剑指_OFFER_27_H
