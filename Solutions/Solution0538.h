//
// Created by irisfeng on 2022/7/28.
//

#ifndef FH_A01_SOLUTION0538_H
#define FH_A01_SOLUTION0538_H

#include "../Common.h"

//538. 把二叉搜索树转换为累加树 mid
//给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），
//使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
//
//提醒一下，二叉搜索树满足下列约束条件：
//
//节点的左子树仅包含键 小于 节点键的节点。
//节点的右子树仅包含键 大于 节点键的节点。
//左右子树也必须是二叉搜索树。

class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }

    void traversal(TreeNode* root){
        if(root == nullptr) return;
        traversal(root->right);
        root->val += sum;
        sum = root->val;
        traversal(root->left);
    }
};

#endif //FH_A01_SOLUTION0538_H
