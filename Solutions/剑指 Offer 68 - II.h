//
// Created by hpf on 22-7-1.
//

#ifndef FH_A01_剑指_OFFER_68_II_H
#define FH_A01_剑指_OFFER_68_II_H

#include "../Common.h"
//剑指 Offer 68 - II. 二叉树的最近公共祖先  ez
//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || p == nullptr || q == nullptr)
            return nullptr;
        if (p->val == root->val || q->val == root->val)
            return root;

        // 先序遍历
        stack<TreeNode *> s;
        unordered_map<int, TreeNode *> father;
        bool is_find_p = false, is_find_q = false;
        s.push(root);
        father[root->val] = nullptr;
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (node->val == p->val)
                is_find_p = true;
            if (node->val == q->val)
                is_find_q = true;
            if (is_find_p && is_find_q)
                break;
            if (node->right) {
                s.push(node->right);
                father[node->right->val] = node;
            }
            if (node->left) {
                s.push(node->left);
                father[node->left->val] = node;
            }
        }
        unordered_map<int, bool> vis;
        while (p != nullptr) {
            vis[p->val] = true;
            p = father[p->val];
        }
        while(q!= nullptr){
            if(vis[q->val])
                return q;
            q=father[q->val];
        }
        return nullptr;

//        vector<TreeNode *> path_p, path_q;
//        TreeNode *cur = p;
//        path_p.push_back(p);
//        unordered_map<TreeNode *, TreeNode *>::iterator iter;
//        while ((iter = father.find(cur)) != father.end()) {
//            cur = iter->second;
//            path_p.push_back(cur);
//        }
//        cur = q;
//        path_q.push_back(q);
//        while ((iter = father.find(cur)) != father.end()) {
//            cur = iter->second;
//            path_q.push_back(cur);
//        }
//        TreeNode* result = nullptr;
//        for (int i = path_p.size() - 1, j = path_q.size() - 1; i >= 0 && j >= 0; --i, --j) {
//            if (path_p[i]->val == path_q[j]->val) {
//                result =  path_p[i];
//            }else{
//                break;
//            }
//        }
//        return result;
    }
};

#endif //FH_A01_剑指_OFFER_68_II_H
