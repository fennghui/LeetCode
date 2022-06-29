//
// Created by hpf on 22-6-29.
//

#ifndef FH_A01_剑指_OFFER_54_H
#define FH_A01_剑指_OFFER_54_H

#include "../Common.h"

//剑指 Offer 54. 二叉搜索树的第k大节点 ez
//给定一棵二叉搜索树，请找出其中第 k 大的节点的值。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * 中序遍历二叉搜索树
 */
class Solution {
public:
//    解法一：
//    int kthLargest(TreeNode *root, int k) {
//        int rank = 0;
//        stack<TreeNode *> s;
//        while (!s.empty() || root != nullptr) {
//            while (root != nullptr) {
//                s.push(root);
//                root = root->right;
//            }
//            auto top = s.top();
//            s.pop();
//            if(--k == 0)
//                return top->val;
//            root = top->left;
//        }
//        return 0;
//    }
    int kthLargest(TreeNode *root, int k) {
        stack<TreeNode *> s;
        while (!s.empty() || root != nullptr) {
            if (root != nullptr) {
                s.push(root);
                root = root->right;
            }else{
                root = s.top();
                s.pop();
                if (--k == 0)
                    return root->val;
                root = root->left;
            }
        }
        return 0;
    }
};

#endif //FH_A01_剑指_OFFER_54_H
