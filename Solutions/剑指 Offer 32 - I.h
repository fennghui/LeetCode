//
// Created by iris on 22-7-10.
//

#ifndef FH_A01_剑指_OFFER_32_I_H
#define FH_A01_剑指_OFFER_32_I_H

#include "../Common.h"

//剑指 Offer 32 - I. 从上到下打印二叉树 mid
//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。


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
    vector<int> levelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};
        queue<TreeNode *> q;
        vector<int> res;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        return res;
    }
};

#endif //FH_A01_剑指_OFFER_32_I_H
