//
// Created by irisfeng on 2023/2/22.
//

#ifndef FH_A01_236_二叉树的最近公共祖先_H
#define FH_A01_236_二叉树的最近公共祖先_H

#include "../Common.h"

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) {
            return nullptr;
        }
        if (root == p || root == q) {
            return root;
        }

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if(left && right){
            return root;
        }
        return left ? left : right;
    }
};

#endif //FH_A01_236_二叉树的最近公共祖先_H
