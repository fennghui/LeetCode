//
// Created by irisfeng on 2022/7/17.
//

#ifndef FH_A01_SOLUTION0145_H
#define FH_A01_SOLUTION0145_H

#include "../Common.h"

// 后序遍历 mid

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

/*
栈遍历版本： 建议先做中序遍历，后序只是在中序上多了一些操作。

与中序的不同之处在于：

中序遍历中，从栈中弹出的节点，其左子树是访问完了，可以直接访问该节点，然后接下来访问右子树。
后序遍历中，从栈中弹出的节点，我们只能确定其左子树肯定访问完了，但是无法确定右子树是否访问过。
因此，我们在后序遍历中，引入了一个prev来记录历史访问记录。

当访问完一棵子树的时候，我们用prev指向该节点。
这样，在回溯到父节点的时候，我们可以依据prev是指向左子节点，还是右子节点，来判断父节点的访问情况。
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode *prev = nullptr;
        while(root != nullptr || !s.empty()){
            while(root != nullptr){
                s.emplace(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(root->right == nullptr || prev == root->right){
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            }else{
                s.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};

vector<int> postorderTraversal1(TreeNode* root) {
    if(root == nullptr)
        return {};
    stack<TreeNode*> s;
    s.push(root);
    vector<int> res;
    while(!s.empty()){
        auto top = s.top();
        s.pop();
        res.push_back(top->val);
        if(top->left != nullptr)
            s.push(top->left);
        if(top->right != nullptr)
            s.push(top->right);
    }
    reverse(res.begin(),res.end());
    return res;
}
#endif //FH_A01_SOLUTION0145_H
