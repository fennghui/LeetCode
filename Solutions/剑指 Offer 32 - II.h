//
// Created by hpf on 22-6-28.
//

#ifndef FH_A01_剑指_OFFER_32_II_H
#define FH_A01_剑指_OFFER_32_II_H

#include "../Common.h"

//剑指 Offer 32 - II. 从上到下打印二叉树 II ez
//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int>> result;
        vector<int> levelResult;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front == nullptr){
                if(!q.empty()){
                    q.push(nullptr);
                }
                result.push_back(levelResult);
                levelResult = vector<int>();
                continue;
            }
            levelResult.push_back(front->val);
            if(front->left != nullptr){
                q.push(front->left);
            }
            if(front->right != nullptr){
                q.push(front->right);
            }
        }
        return result;
    }
};

#endif //FH_A01_剑指_OFFER_32_II_H
