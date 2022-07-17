//
// Created by irisfeng on 2022/7/17.
//

#ifndef FH_A01_SOLUTION0144_H
#define FH_A01_SOLUTION0144_H

#include "../Common.h"

//144. 二叉树的前序遍历 ez
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

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
    // 迭代写法
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        stack<TreeNode*> s;
        s.push(root);
        vector<int> res;
        while(!s.empty()){
            auto top  = s.top();
            s.pop();
            res.push_back(top->val); // 中
            if(top->right != nullptr) // 右
                s.push(top->right);
            if(top->left != nullptr) // 左
                s.push(top->left);
        }
        return res;
    }
};

/*
void travelsal(TreeNode* root, vector<int> &result){
    if(root == nullptr)
        return;
    result.push_back(root->val);
    travelsal(root->left, result);
    travelsal(root->right,result);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    travelsal(root, res);
    return res;
}
*/


#endif //FH_A01_SOLUTION0144_H
