//
// Created by iris on 22-7-9.
//

#ifndef FH_A01_剑指_OFFER_26_H
#define FH_A01_剑指_OFFER_26_H

#include "../Common.h"

//剑指 Offer 26. 树的子结构 mid
//输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
//
//B是A的子结构， 即 A中有出现和B相同的结构和节点值。

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
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (B == nullptr || A == nullptr)
            return false;
        return traverse(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    // 从根节点判断B是不是A的子树
    bool traverse(TreeNode *A, TreeNode *B) {
        if (B == nullptr) {
            return true;
        }
        if (A == nullptr) {
            return false;
        }
        if (A->val != B->val)
            return false;
        return traverse(A->right, B->right) && traverse(A->left, B->left);
    }

};

#endif //FH_A01_剑指_OFFER_26_H
