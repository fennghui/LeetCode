//
// Created by irisfeng on 2023/2/22.
//

#ifndef FH_A01_102_二叉树的层序遍历_H
#define FH_A01_102_二叉树的层序遍历_H

#include "../Common.h"

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
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        if (root) {
            q.push(root);
            q.push(nullptr);
        }
        vector<vector<int>> res;
        vector<int> level;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (top) {
                level.push_back(top->val);
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }else{
                res.push_back(level);
                level = {};
                if(q.empty()){
                    break;
                }
                q.push(nullptr);
            }
        }
        return res;
    }
};


#endif //FH_A01_102_二叉树的层序遍历_H
