//
// Created by irisfeng on 2022/7/17.
//

#ifndef FH_A01_SOLUTION0111_H
#define FH_A01_SOLUTION0111_H

#include "../Common.h"

//111. 二叉树的最小深度 ez
//给定一个二叉树，找出其最小深度。
//
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
//说明：叶子节点是指没有子节点的节点。

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
    int minDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int minDep = 0;
        while (!q.empty()) {
            int size = q.size();
            ++minDep;
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                if(cur->left == nullptr && cur->right == nullptr){
                    return minDep;
                }
                if(cur->left != nullptr)
                    q.push(cur->left);
                if(cur->right != nullptr)
                    q.push(cur->right);
            }
        }
        return minDep;
    }
};

#endif //FH_A01_SOLUTION0111_H
