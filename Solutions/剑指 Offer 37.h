//
// Created by irisfeng on 2022/7/14.
//

#ifndef FH_A01_剑指_OFFER_37_H
#define FH_A01_剑指_OFFER_37_H

#include "../Common.h"

//剑指 Offer 37. 序列化二叉树 hard
//请实现两个函数，分别用来序列化和反序列化二叉树。
//
//你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，
//你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
//
//提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。
//你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr)
            return "";
        queue<TreeNode *> q;
        q.push(root);
        string res = "";
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (top != nullptr) {
                res += to_string(top->val) + ",";
                q.push(top->left);
                q.push(top->right);
            } else {
                res += "null,";
            }
        }
        res.erase(res.size() - 1, 1);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "")
            return nullptr;
        vector<string> strList;
        string delimiter = ",";

        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                strList.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            strList.push_back(str);
            str.clear();
        }

        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(stoi(strList[0]));
        q.push(root);
        int i = 1;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(strList[i] != "null"){
                top->left = new TreeNode(stoi(strList[i]));
                q.push(top->left);
            }
            ++i;
            if(strList[i] != "null"){
                top->right = new TreeNode(stoi(strList[i]));
                q.push(top->right);
            }
            ++i;
        }
        return root;
    }


};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

#endif //FH_A01_剑指_OFFER_37_H
