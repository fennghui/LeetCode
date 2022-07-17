//
// Created by irisfeng on 2022/7/17.
//

#ifndef FH_A01_SOLUTION0094_H
#define FH_A01_SOLUTION0094_H

#include "../Common.h"

// 94 中序遍历 mid 迭代

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        while(root != nullptr || !s.empty()){
            while(root != nullptr){
                s.emplace(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            res.emplace_back(root->val);
            if(root->right != nullptr){
                root = root->right;
            }else{
                root = nullptr;
            }
        }
        return res;
    }
};

#endif //FH_A01_SOLUTION0094_H
