//
// Created by irisfeng on 2022/7/17.
//

#ifndef FH_A01_SOLUTION0226_H
#define FH_A01_SOLUTION0226_H

#include "../Common.h"

//226. 翻转二叉树 ez
//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto cur = s.top();
            s.pop();
            if(cur->left != nullptr)
                s.push(cur->left);
            if(cur->right != nullptr)
                s.push(cur->right);
            auto tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
        }
        return root;
    }
};


TreeNode* invertTree_recur(TreeNode* root) {
    if(root == nullptr)
        return nullptr;
    TreeNode *left = invertTree_recur(root->left);
    TreeNode *right = invertTree_recur(root->right);
    root->left = right;
    root->right = left;
    return root;
}

#endif //FH_A01_SOLUTION0226_H
