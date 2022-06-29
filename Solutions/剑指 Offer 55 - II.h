//
// Created by hpf on 22-6-29.
//

#ifndef FH_A01_剑指_OFFER_55_II_H
#define FH_A01_剑指_OFFER_55_II_H

#include "../Common.h"

//剑指 Offer 55 - II. 平衡二叉树 ez
//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int length(TreeNode *root){
        if(root == nullptr)
            return 0;
        return max(length(root->left), length(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(length(root->left)- length(root->right)) <= 1;
    }
};

#endif //FH_A01_剑指_OFFER_55_II_H
