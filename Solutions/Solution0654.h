//
// Created by irisfeng on 2022/7/20.
//

#ifndef FH_A01_SOLUTION0654_H
#define FH_A01_SOLUTION0654_H

#include "../Common.h"

//654. 最大二叉树 mid
//给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
//
//创建一个根节点，其值为 nums 中的最大值。
//递归地在最大值 左边 的 子数组前缀上 构建左子树。
//递归地在最大值 右边 的 子数组后缀上 构建右子树。
//返回 nums 构建的 最大二叉树 。

class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        int n = nums.size();
        return traversal(nums, 0, n-1);
    }

    TreeNode *traversal(vector<int> &nums, int begin, int end) {
        if (begin > end)
            return nullptr;

        int maxValue = nums[begin];
        int maxIndex = begin;
        for (int i = begin + 1; i <= end; ++i) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxIndex = i;
            }
        }

        TreeNode *node = new TreeNode(maxValue);
        node->left = traversal(nums, begin, maxIndex - 1);
        node->right = traversal(nums, maxIndex + 1, end);
        return node;
    }
};

#endif //FH_A01_SOLUTION0654_H
