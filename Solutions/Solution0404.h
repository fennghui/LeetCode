//
// Created by irisfeng on 2022/7/18.
//

#ifndef FH_A01_SOLUTION0404_H
#define FH_A01_SOLUTION0404_H

#include "../Common.h"

//404. 左叶子之和 ez
//给定二叉树的根节点 root ，返回所有左叶子之和。

class Solution {
public:

    int sumOfLeftLeaves(TreeNode *root) {
        int res = 0;
        if (root == nullptr)
            return res;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            if(cur->left != nullptr){
                if(cur->left->left == nullptr && cur->left->right == nullptr){
                    res += cur->left->val;
                }else{
                    s.push(cur->left);
                }
            }
            if(cur->right != nullptr){
                s.push(cur->right);
            }
        }
        return res;
    }
};

#endif //FH_A01_SOLUTION0404_H
