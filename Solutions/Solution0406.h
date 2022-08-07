//
// Created by irisfeng on 2022/8/7.
//

#ifndef FH_A01_SOLUTION0406_H
#define FH_A01_SOLUTION0406_H

#include "../Common.h"

//406. 根据身高重建队列 mid
//假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
//每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
//
//请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，
//其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> res(people.size());

        for(int i = 0; i < people.size(); ++i){
            int space = people[i][1] + 1;
            for(int j = 0; j < people.size(); j++){
                if(res[j].empty()){
                    --space;
                    if(!space){
                        res[j] = people[i];
                        break;
                    }
                }
            }
        }
        return res;
    }
};

#endif //FH_A01_SOLUTION0406_H
