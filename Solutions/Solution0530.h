//
// Created by irisfeng on 2022/7/21.
//

#ifndef FH_A01_SOLUTION0530_H
#define FH_A01_SOLUTION0530_H

#include "../Common.h"

//530. 二叉搜索树的最小绝对差 ez
//给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
//
//差值是一个正数，其数值等于两值之差的绝对值。

class Solution {
public:
    int mini = INT32_MAX;
    TreeNode *prev = nullptr;

    int getMinimumDifference(TreeNode *root) {
        if (root == nullptr)
            return mini;

        getMinimumDifference(root->left);
        if (prev != nullptr) {
            mini = min(mini, root->val - prev->val);
        }
        prev = root;
        getMinimumDifference(root->right);

        return mini;
    }
};

#endif //FH_A01_SOLUTION0530_H
