//
// Created by irisfeng on 2023/2/2.
//

#ifndef FH_A01_98_验证二叉搜索树_H
#define FH_A01_98_验证二叉搜索树_H

#include "../Common.h"

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
    /**
     * 中序遍历
     */
    TreeNode *pre = nullptr;
    bool isValidBST(TreeNode *root) {
        if (!root) {
            return true;
        }
        auto left = isValidBST(root->left);
        if (pre != nullptr && pre->val >= root->val) {
            return false;
        }
        pre = root;
        auto right = isValidBST(root->right);
        return left && right;
    }
};

#endif //FH_A01_98_验证二叉搜索树_H
