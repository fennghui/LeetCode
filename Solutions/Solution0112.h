//
// Created by irisfeng on 2022/7/18.
//

#ifndef FH_A01_SOLUTION0112_H
#define FH_A01_SOLUTION0112_H

#include "../Common.h"

//112. 路径总和 ez
//给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
//
//叶子节点 是指没有子节点的节点。

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        unordered_map<TreeNode*, int> umap;
        stack<TreeNode*> s;
        if(root != nullptr){
            s.push(root);
            umap[root] = root->val;
        }
        while(!s.empty()){
            auto cur = s.top();
            s.pop();
            if(cur->left == nullptr && cur->right == nullptr){
                if(umap[cur] == targetSum)
                    return true;
            }
            if(cur->left != nullptr){
                s.push(cur->left);
                umap[cur->left] = umap[cur] + cur->left->val;
            }
            if(cur->right != nullptr){
                s.push(cur->right);
                umap[cur->right] = umap[cur] + cur->right->val;
            }
        }
        return false;
    }
};

#endif //FH_A01_SOLUTION0112_H
