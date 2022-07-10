//
// Created by iris on 22-7-10.
//

#ifndef FH_A01_剑指_OFFER_34_H
#define FH_A01_剑指_OFFER_34_H

#include "../Common.h"

//剑指 Offer 34. 二叉树中和为某一值的路径 mid
//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
//
//叶子节点 是指没有子节点的节点。

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
    // 将变量设置为全局的，减少空间消耗，尤其是在回溯的时候
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode *root, int target) {
        recur(root, target);
        return res;
    }

    void recur(TreeNode *root, int target) {
        if (root == nullptr)
            return;
        target -= root->val;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && target == 0) {
            res.push_back(path);
        }
        recur(root->left, target);
        recur(root->right, target);
        path.pop_back();
    }
};

#endif //FH_A01_剑指_OFFER_34_H
