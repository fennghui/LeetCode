//
// Created by irisfeng on 2022/7/17.
//

#ifndef FH_A01_SOLUTION0589_H
#define FH_A01_SOLUTION0589_H

#include "../Common.h"

//589. N 叉树的前序遍历 ez
//给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。
//
//n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    void traversal(Node *root, vector<int> &result){
        if(root == nullptr)
            return;
        result.push_back(root->val);
        for(int i =0; i < root->children.size(); ++i){
            traversal(root->children[i], result);
        }
    }
};

#endif //FH_A01_SOLUTION0589_H
