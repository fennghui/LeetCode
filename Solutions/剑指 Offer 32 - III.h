//
// Created by iris on 22-7-10.
//

#ifndef FH_A01_剑指_OFFER_32_III_H
#define FH_A01_剑指_OFFER_32_III_H

#include "../Common.h"

//剑指 Offer 32 - III. 从上到下打印二叉树 III mid
//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        deque<TreeNode *> q;
        q.push_back(root);
        int direction = 0;
        while (!q.empty()) {
            int currentSize = q.size();
            ret.push_back(vector<int>());
            for (int i = 0; i < currentSize; ++i) {
                TreeNode *node;
                if (direction) {
                    node = q.back();
                    q.pop_back();
                }else{
                    node = q.front();
                    q.pop_front();
                }
                ret.back().push_back(node->val);
                if (direction) {
                    if (node->right != nullptr)
                        q.push_front(node->right);
                    if (node->left != nullptr)
                        q.push_front(node->left);
                } else {
                    if (node->left != nullptr)
                        q.push_back(node->left);
                    if (node->right != nullptr)
                        q.push_back(node->right);
                }
            }
            direction = (direction + 1) % 2;
        }
        return ret;
    }
};

#endif //FH_A01_剑指_OFFER_32_III_H
