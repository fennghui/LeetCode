//
// Created by irisfeng on 2023/1/27.
//

#ifndef FH_A01_698_划分为K个相等的子集_H
#define FH_A01_698_划分为K个相等的子集_H

#include "../Common.h"

/**
 * 回溯
 */

class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        if (k == 1) {
            return true;
        }
        int sum = 0;
        for (auto &num: nums) {
            sum += num;
        }
        /// 无法整除，说明一定不存在
        int partition_sum = sum / k;
        if (sum != partition_sum * k) {
            return false;
        }
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (nums[len - 1] > partition_sum) {
            return false;
        }
        vector<int> buckets(k, partition_sum);
        return backTracking(nums, k, len - 1, buckets);
    }

    bool backTracking(vector<int> &nums, int k, int cur, vector<int> &buckets) {
        if (cur < 0) {
            return true;
        }
        /// 对所有可能的情况做回溯
        for (int i = 0; i < k; i++) {
            if (buckets[i] == nums[cur] || buckets[i] - nums[cur] >= nums[0]) { /// 做剪枝
                if(i > 0 && buckets[i] == buckets[i - 1]) continue; /// 没有这句话，就超时
                buckets[i] -= nums[cur];
                if (backTracking(nums, k, cur - 1, buckets)) {
                    return true;
                }
                buckets[i] += nums[cur];
            }
        }
        return false;
    }
};

#endif //FH_A01_698_划分为K个相等的子集_H
