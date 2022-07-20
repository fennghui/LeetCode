//
// Created by irisfeng on 2022/7/20.
//

#ifndef FH_A01_SOLUTION0105_H
#define FH_A01_SOLUTION0105_H

#include "../Common.h"

//105. 从前序与中序遍历序列构造二叉树 mid
//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
//inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

class Solution {
public:
    unordered_map<int, int> uMap;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i)
            uMap[inorder[i]] = i;
        return traversal(preorder,0,n-1,inorder,0,n-1);
    }

    TreeNode *traversal(vector<int> &preorder, int preBegin, int preEnd, vector<int> &inorder, int inBegin, int inEnd) {
        if (inBegin > inEnd)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[preBegin]);
        int leftN = uMap[preorder[preBegin]] - 1 - inBegin;
        node->left = traversal(preorder, preBegin + 1, preBegin + 1 + leftN, inorder, inBegin, inBegin + leftN);
        int rightN = inEnd - (uMap[preorder[preBegin]] + 1);
        node->right = traversal(preorder, preEnd - rightN, preEnd, inorder, inEnd - rightN, inEnd);
        return node;
    }
};

#endif //FH_A01_SOLUTION0105_H
