//
// Created by irisfeng on 2022/7/20.
//

#ifndef FH_A01_SOLUTION0098_H
#define FH_A01_SOLUTION0098_H

#include "../Common.h"

//98. 验证二叉搜索树 mid
//给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
//
//有效 二叉搜索树定义如下：
//
//节点的左子树只包含 小于 当前节点的数。
//节点的右子树只包含 大于 当前节点的数。
//所有左子树和右子树自身必须也是二叉搜索树。

class Solution {
public:
    // 中序遍历！！！
    vector<int> traResult;
    bool isValidBST(TreeNode* root) {
        traversal(root);
        for(int i = 1; i < traResult.size(); ++i){
            if(traResult[i] <= traResult[i-1])
                return false;
        }
        return true;
    }

    void traversal(TreeNode* root){
        if(root == nullptr)
            return;
        traversal(root->left);
        traResult.push_back(root->val);
        traversal(root->right);
    }

};

#endif //FH_A01_SOLUTION0098_H
