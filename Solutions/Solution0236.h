//
// Created by irisfeng on 2022/7/21.
//

#ifndef FH_A01_SOLUTION0236_H
#define FH_A01_SOLUTION0236_H

#include "../Common.h"

//236. 二叉树的最近公共祖先 mid
//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
//满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode *comLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode *comRight = lowestCommonAncestor(root->right, p, q);
        if (comLeft != nullptr && comRight != nullptr)
            return root;
        return (comLeft != nullptr) ? comLeft : comRight;
    }
};

#endif //FH_A01_SOLUTION0236_H
