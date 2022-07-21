//
// Created by irisfeng on 2022/7/21.
//

#ifndef FH_A01_SOLUTION0501_H
#define FH_A01_SOLUTION0501_H

#include "../Common.h"

//501. 二叉搜索树中的众数 ez
//给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
//
//如果树中有不止一个众数，可以按 任意顺序 返回。
//
//假定 BST 满足如下定义：
//
//结点左子树中所含节点的值 小于等于 当前节点的值
//结点右子树中所含节点的值 大于等于 当前节点的值
//左子树和右子树都是二叉搜索树

class Solution {
public:
    int maxFre;
    int curFre;
    TreeNode *prev = nullptr;
    vector<int> res;

    vector<int> findMode(TreeNode *root) {
        res.clear();
        maxFre = 0;
        curFre = 0;
        prev = nullptr;
        traversal(root);
        return res;
    }

    void traversal(TreeNode *root) {
        if (root == nullptr) return;
        traversal(root->left);
        if (prev == nullptr) {
            curFre = 1;
        } else if (prev->val == root->val) {
            ++curFre;
        } else {
            curFre = 1;
        }
        if (curFre == maxFre) {
            res.push_back(root->val);
        }
        if (curFre > maxFre) {
            maxFre = curFre;
            res.clear();
            res.push_back(root->val);
        }
        prev = root;
        traversal(root->right);
    }
};


#endif //FH_A01_SOLUTION0501_H
