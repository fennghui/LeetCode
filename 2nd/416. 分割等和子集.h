//
// Created by irisfeng on 2023/1/30.
//

#ifndef FH_A01_416_分割等和子集_H
#define FH_A01_416_分割等和子集_H

#include "../Common.h"


/**
 * 回溯法超时了
 * 还是得用动态规划 背包问题
 */
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (auto &num: nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int partSum = sum / 2;
        vector<bool> dp(partSum + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i) { /// 物品
            for (int j = partSum; j >= nums[i]; --j) { /// 背包，倒序遍历
                dp[j] = dp[j] || dp[j - nums[i]]; /// 背包中放入物品 i
            }
        }

        return dp[partSum];
    }
};

//class Solution {
//public:
//    bool canPartition(vector<int>& nums) {
//        int sum = 0;
//        for(auto &num : nums){
//            sum += num;
//        }
//        if(sum % 2 != 0){
//            return false;
//        }
//        int partSum = sum / 2;
//        sort(nums.begin(),nums.end());
//        if(nums[nums.size()-1] > partSum){
//            return false;
//        }
//        vector<int> bucket(2, partSum);
//        return backTracking(nums, nums.size()-1, bucket);
//    }
//
//    bool backTracking(vector<int>& nums, int startIndex, vector<int> &bucket){
//        if(startIndex < 0){
//            return true;
//        }
//
//        for(int i = 0; i < 2; ++i){
//            if(bucket[i] - nums[startIndex] >= nums[0] || bucket[i] == nums[startIndex]){
//                bucket[i] -= nums[startIndex];
//                if(backTracking(nums, startIndex - 1, bucket)){
//                    return true;
//                }
//                bucket[i] += nums[startIndex];
//            }
//        }
//        return false;
//    }
//};

#endif //FH_A01_416_分割等和子集_H
