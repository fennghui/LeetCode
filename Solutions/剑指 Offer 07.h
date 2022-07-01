//
// Created by hpf on 22-7-1.
//

#ifndef FH_A01_剑指_OFFER_07_H
#define FH_A01_剑指_OFFER_07_H

#include "../Common.h"
//剑指 Offer 07. 重建二叉树 mid
//输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
//
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty())
            return nullptr;
        int n = preorder.size();
        stack<TreeNode *> s;
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *cur_node = root;
        s.push(root);
        int cur_pre = 1;
        int cur_in = 0;
        while (!s.empty() && cur_pre < n && cur_in < n) {
            while (s.top()->val != inorder[cur_in] && cur_pre < n) {
                cur_node->left = new TreeNode(preorder[cur_pre++]);
                cur_node = cur_node->left;
                s.push(cur_node);
            }
            while (cur_in < n && !s.empty() && s.top()->val == inorder[cur_in]) {
                cur_node = s.top();
                s.pop();
                ++cur_in;
            }
            if (cur_pre < n && cur_node != nullptr) {
                cur_node->right = new TreeNode(preorder[cur_pre++]);
                s.push(cur_node->right);
                cur_node = cur_node->right;
            }
        }
        return root;
    }
};

#endif //FH_A01_剑指_OFFER_07_H
