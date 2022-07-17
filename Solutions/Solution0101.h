//
// Created by irisfeng on 2022/7/17.
//

#ifndef FH_A01_SOLUTION0101_H
#define FH_A01_SOLUTION0101_H

#include "../Common.h"

//101. 对称二叉树 ez
//给你一个二叉树的根节点 root ， 检查它是否轴对称。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            auto curS1 = q.front();
            q.pop();
            auto curS2 = q.front();
            q.pop();
            if (curS1 == nullptr && curS2 == nullptr)
                continue;
            if (curS1 == nullptr || curS2 == nullptr || curS1->val != curS2->val)
                return false;

            q.push(curS1->left);
            q.push(curS2->right);

            q.push(curS1->right);
            q.push(curS2->left);
        }
        return true;
    }
};

//class Solution {
//public:
//    bool isSymmetric(TreeNode* root) {
//        if(root == nullptr)
//            return true;
//        return isSame(root->left,root->right);
//    }
//
//    bool isSame(TreeNode *t1, TreeNode *t2){
//        if(t1 == nullptr && t2 == nullptr)
//            return true;
//        if(t1 == nullptr || t2== nullptr)
//            return false;
//        if(t1->val != t2->val)
//            return false;
//        return isSame(t1->left, t2->right) && isSame(t1->right, t2->left);
//    }
//};

#endif //FH_A01_SOLUTION0101_H
