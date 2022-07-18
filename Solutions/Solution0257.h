//
// Created by irisfeng on 2022/7/18.
//

#ifndef FH_A01_SOLUTION0257_H
#define FH_A01_SOLUTION0257_H

#include "../Common.h"

//257. 二叉树的所有路径 ez
//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
//
//叶子节点 是指没有子节点的节点。

class Solution {
public:
    vector<string> res;

    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == nullptr)
            return {};
        res.clear();
        string path = "";
        traversal(root, path);
        return res;
    }

    void traversal(TreeNode *root, string path) {
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            return;
        }
        if (root->left != nullptr) {
            traversal(root->left, path + "->");
        }

        if (root->right != nullptr) {
            traversal(root->right, path + "->");
        }
    }
};

#endif //FH_A01_SOLUTION0257_H
