//
// Created by irisfeng on 2023/1/25.
//

#ifndef FH_A01_18_四数之和_H
#define FH_A01_18_四数之和_H

#include "../Common.h"

/**
 * 这道题去重的思路很关键
 *
 * 1. 去重搞了很久
 * 2. runtime error: signed integer overflow: 2000000000 + 1000000000 cannot be represented in type 'int'
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        if (n < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); ++i) {
//            cout << nums[i] << " ";
//        }
//        cout << endl;
        vector<vector<int>> res;
        for (int i = 0; i < n - 3; i++) {
            /// 去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            cout << "i " << i << " nums[i] " << nums[i] << endl;
            for (int j = i + 1; j < n - 2;) {
                /// 去重
                while (j - 1 > i && j < n-2 && nums[j] == nums[j - 1]) {
                    j++;
                }
                cout << "j " << j << " nums[j] " << nums[j] << endl;
                for (int k = j + 1, l = n - 1; k < l;) {


                    cout << "k " << k << " nums[k] " << nums[k] << endl;
                    cout << "l " << l << " nums[l] " << nums[l] << endl;

                    long int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        /// 去重
                        while (k + 1 < l && nums[k] == nums[k + 1]) {
                            k++;
                        }
                        k++;
                        /// 去重
                        while (l - 1 > k && nums[l] == nums[l - 1]) {
                            l--;
                        }
                        l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
                j++;
            }
        }
        return res;
    }
};

#endif //FH_A01_18_四数之和_H
