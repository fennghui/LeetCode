//
// Created by irisfeng on 2022/7/20.
//

#ifndef FH_A01_SOLUTION0113_H
#define FH_A01_SOLUTION0113_H

#include "../Common.h"

//113. 路径总和 II mid
//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
//
//叶子节点 是指没有子节点的节点。

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        path.clear();
        if(root != nullptr){
            path.push_back(root->val);
            traversal(root, targetSum - root->val);
        }
        return res;
    }

    void traversal(TreeNode* root, int count){
        if(root->left == nullptr && root->right == nullptr && count == 0){
            res.push_back(path);
            return;
        }
        if(root->left == nullptr && root->right == nullptr)
            return;
        if(root->left != nullptr){
            path.push_back(root->left->val);
            traversal(root->left, count - root->left->val);
            path.pop_back();
        }
        if(root->right != nullptr){
            path.push_back(root->right->val);
            traversal(root->right, count - root->right->val);
            path.pop_back();
        }
    }
};

#endif //FH_A01_SOLUTION0113_H
