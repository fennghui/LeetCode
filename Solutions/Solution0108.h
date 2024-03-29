//
// Created by irisfeng on 2022/7/28.
//

#ifndef FH_A01_SOLUTION0108_H
#define FH_A01_SOLUTION0108_H

#include "../Common.h"

//108. 将有序数组转换为二叉搜索树 ez
//给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
//
//高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums,0,nums.size()-1);
    }

    TreeNode* traversal(vector<int>& nums, int left, int right){
        if(left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = traversal(nums, left, mid - 1);
        cur->right = traversal(nums, mid + 1, right);
        return cur;
    }
};

#endif //FH_A01_SOLUTION0108_H
