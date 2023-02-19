//
// Created by irisfeng on 2023/2/3.
//

#ifndef FH_A01_95_不同的二叉搜索树_II_H
#define FH_A01_95_不同的二叉搜索树_II_H

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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int begin, int end) {
        if (begin > end) {
            return {nullptr};
        }
        vector<TreeNode *> allTress;
        for (int i = begin; i <= end; ++i) {
            vector<TreeNode *> leftTrees = generateTrees(begin, i - 1);
            vector<TreeNode *> rightTrees = generateTrees(i + 1, end);
            for (auto &left: leftTrees) {
                for (auto &right: rightTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    allTress.push_back(root);
                }
            }
        }
        return allTress;
    }
};

#endif //FH_A01_95_不同的二叉搜索树_II_H
