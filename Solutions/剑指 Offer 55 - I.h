//
// Created by hpf on 22-6-29.
//

#ifndef FH_A01_剑指_OFFER_55_I_H
#define FH_A01_剑指_OFFER_55_I_H

#include "../Common.h"

//剑指 Offer 55 - I. 二叉树的深度 ez
//输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight) + 1;
    }
};

#endif //FH_A01_剑指_OFFER_55_I_H
