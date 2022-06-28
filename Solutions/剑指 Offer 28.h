//
// Created by hpf on 22-6-28.
//

#ifndef FH_A01_剑指_OFFER_28_H
#define FH_A01_剑指_OFFER_28_H

#include "../Common.h"

//剑指 Offer 28. 对称的二叉树
//请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
//
//例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            auto tree1 = q.front();
            q.pop();
            auto tree2 = q.front();
            q.pop();
            if(tree1== nullptr && tree2 == nullptr)
                continue;
            if(tree1 == nullptr || tree2 == nullptr || tree1->val != tree2->val)
                return false;
            q.push(tree1->left);
            q.push(tree2->right);
            q.push(tree1->right);
            q.push(tree2->left);
        }
        return true;
    }
};

#endif //FH_A01_剑指_OFFER_28_H
