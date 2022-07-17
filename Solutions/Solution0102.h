//
// Created by irisfeng on 2022/7/17.
//

#ifndef FH_A01_SOLUTION0102_H
#define FH_A01_SOLUTION0102_H

#include "../Common.h"

// 层序遍历 mid

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            int curSize = q.size();
            vector<int> tmp;
            for(int i = 0; i < curSize; ++i){
                auto cur = q.front();
                q.pop();
                tmp.emplace_back(cur->val);
                if(cur->left != nullptr)
                    q.emplace(cur->left);
                if(cur->right != nullptr)
                    q.emplace(cur->right);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};

#endif //FH_A01_SOLUTION0102_H
