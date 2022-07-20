//
// Created by irisfeng on 2022/7/20.
//

#ifndef FH_A01_SOLUTION0617_H
#define FH_A01_SOLUTION0617_H

#include "../Common.h"

//617. 合并二叉树 ez
//给你两棵二叉树： root1 和 root2 。
//
//想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。
//你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的
//值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。
//
//返回合并后的二叉树。
//
//注意: 合并过程必须从两个树的根节点开始。

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr)
            return nullptr;
        TreeNode *root = root1;
        if(root1 != nullptr && root2 != nullptr){
            root->val = root1->val + root2->val;
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
        }else if(root2 != nullptr){
            root = root2;
        }
        return root;
    }
};

#endif //FH_A01_SOLUTION0617_H
