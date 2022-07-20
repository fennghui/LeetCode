//
// Created by irisfeng on 2022/7/20.
//

#ifndef FH_A01_SOLUTION0106_H
#define FH_A01_SOLUTION0106_H

#include "../Common.h"

//106. 从中序与后序遍历序列构造二叉树 mid
//给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历，
//postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

class Solution {
public:
    unordered_map<int, int> umap;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            umap[inorder[i]] = i;
        }
        return recur(inorder, 0, n - 1, postorder, 0, n - 1);
    }

    TreeNode *recur(vector<int> &inorder, int in_le, int in_ri, vector<int> &postorder, int post_le, int post_ri) {
        if (in_le > in_ri)
            return nullptr;
        auto *node = new TreeNode(postorder[post_ri]);
        int leftN = umap[postorder[post_ri]] - 1 - in_le;
        node->left = recur(inorder, in_le, in_le + leftN, postorder, post_le, post_le + leftN);
        int rightN = in_ri - (umap[postorder[post_ri]] + 1);
        node->right = recur(inorder, in_ri - rightN, in_ri, postorder, post_ri - 1 - rightN, post_ri - 1);
        return node;
    }

};

#endif //FH_A01_SOLUTION0106_H
