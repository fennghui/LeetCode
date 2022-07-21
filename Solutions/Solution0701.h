//
// Created by irisfeng on 2022/7/22.
//

#ifndef FH_A01_SOLUTION0701_H
#define FH_A01_SOLUTION0701_H

#include "../Common.h"

//701. 二叉搜索树中的插入操作 mid
//给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。
//返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。
//
//注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *cur = root;
        TreeNode *prev = nullptr;
        int flag = -1;
        while(cur != nullptr){
            prev = cur;
            if(val < cur->val) {
                cur = cur->left;
                flag = 0;
            }else if(val > cur->val){
                cur = cur->right;
                flag = 1;
            }
        }
        cur = new TreeNode(val);
        if(flag == 1)
            prev->right = cur;
        else if(flag == 0)
            prev->left = cur;
        else
            root = cur;

        return root;
    }
};

#endif //FH_A01_SOLUTION0701_H
