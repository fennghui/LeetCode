//
// Created by irisfeng on 2023/1/30.
//

#ifndef FH_A01_46_全排列_H
#define FH_A01_46_全排列_H

#include "../Common.h"

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(),false);
        backTracking(nums, visited);
        return res;
    }

    void backTracking(vector<int>& nums, vector<bool> &visited){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!visited[i]){
                visited[i] = true;
                path.push_back(nums[i]);
                backTracking(nums, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
};

#endif //FH_A01_46_全排列_H
