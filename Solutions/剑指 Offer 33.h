//
// Created by iris on 22-7-10.
//

#ifndef FH_A01_剑指_OFFER_33_H
#define FH_A01_剑指_OFFER_33_H

#include "../Common.h"

//剑指 Offer 33. 二叉搜索树的后序遍历序列 mid
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

class Solution {
public:

    bool verifyPostorder(vector<int> &postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }

    bool recur(vector<int> &postorder, int left, int right) {
        if (left >= right) {
            return true;
        }
        int l = left;
        while (postorder[l] < postorder[right]) {
            ++l;
        }
        int r = l;
        while (postorder[l] > postorder[right]) {
            ++l;
        }
        return l == right && recur(postorder, left, r - 1) && recur(postorder, r, right - 1);
    }
};

//bool verifyPostorder(vector<int> &postorder) {
//    int n = postorder.size();
//    if (n <= 2)
//        return true;
//    int root = postorder[n - 1];
//    int left = 0;
//    while (left < n && postorder[left] < root) {
//        ++left;
//    }
//
//    int right = postorder.size() - 2;
//    while (right >= 0 && postorder[right] > root) {
//        --right;
//    }
//
//    if (left != right + 1)
//        return false;
//
//    vector<int> a, b;
//    a.assign(postorder.begin(), postorder.begin() + left);
//    b.assign(postorder.begin() + left, postorder.end() - 1);
//    return verifyPostorder(a) && verifyPostorder(b);
//}


#endif //FH_A01_剑指_OFFER_33_H
