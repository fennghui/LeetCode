//
// Created by hpf on 22-5-30.
//

#ifndef FH_A01_COMMON_H
#define FH_A01_COMMON_H

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* initTree(vector<string>& vec)
{
    queue<TreeNode*> qu;
    TreeNode* root = new TreeNode(atoi(vec[0].c_str()));
    int i = 1;
    qu.push(root);
    while (!qu.empty())
    {
        int len = qu.size();
        while (len--)
        {
            TreeNode* node = qu.front();
            qu.pop();
            if (vec[i] != "null")
            {
                node->left = new TreeNode(atoi(vec[i].c_str()));
                qu.push(node->left);
            }
            i++;
            if (i == vec.size())
                return root;
            if (vec[i] != "null")
            {
                node->right = new TreeNode(atoi(vec[i].c_str()));
                qu.push(node->right);
            }
            i++;
            if (i == vec.size())
                return root;
        }
    }
    return root;
}

//  ************* 输出图形二叉树 *************
void output_impl(TreeNode* n, bool left, string const& indent)
{
    if (n->right)
    {
        output_impl(n->right, false, indent + (left ? "|     " : "      "));
    }
    cout << indent;
    cout << (left ? '\\' : '/');
    cout << "-----";
    cout << n->val << endl;
    if (n->left)
    {
        output_impl(n->left, true, indent + (left ? "      " : "|     "));
    }
}

void output(TreeNode* root)
{
    if (root->right)
    {
        output_impl(root->right, false, "");
    }
    cout << root->val << endl;
    if (root->left)
    {
        output_impl(root->left, true, "");
    }
}


#endif //FH_A01_COMMON_H
