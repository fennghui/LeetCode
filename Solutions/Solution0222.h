//
// Created by hpf on 22-6-12.
//

#ifndef FH_A01_SOLUTION0222_H
#define FH_A01_SOLUTION0222_H

#include "../Common.h"

//222. 完全二叉树的节点个数 mid
//给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
//
//完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2^h 个节点。

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        // 求左树的高度
        int heightL = height(root->left);
        // 求右树的高度
        int heightR = height(root->right);
        int num = 0;
        if(heightL == heightR){
            num = countNodes(root->right);
            return num + (1<<heightL);
        }else{
            num = countNodes(root->left);
            return num + (1<<heightR);
        }
    }
    // 对完全二叉树的左孩子一直遍历，即可得到树的高度，log(n)
    int height(TreeNode * root){
        int h = 0;
        TreeNode* p = root;
        while(p != nullptr){
            ++h;
            p = p->left;
        }
        return h;
    }

};

#endif //FH_A01_SOLUTION0222_H
