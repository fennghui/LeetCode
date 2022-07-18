//
// Created by irisfeng on 2022/7/18.
//

#ifndef FH_A01_SOLUTION0513_H
#define FH_A01_SOLUTION0513_H

#include "../Common.h"

//513. 找树左下角的值 mid
//给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
//
//假设二叉树中至少有一个节点。

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> q;
        if (root != nullptr) q.push(root);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                if (i == 0) res = cur->val;
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
        }
        return res;
    }
};

#endif //FH_A01_SOLUTION0513_H
