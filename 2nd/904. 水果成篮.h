//
// Created by irisfeng on 2023/1/28.
//

#ifndef FH_A01_904_水果成篮_H
#define FH_A01_904_水果成篮_H

#include "../Common.h"

class Solution {
public:
    int totalFruit(vector<int> &fruits) {
        int n = fruits.size();
        int res = 0;
        set<int> fruitSet;
        int curStart = 0;
        for (int i = 0; i < n;) {
            if (fruitSet.size() < 2 && fruitSet.find(fruits[i]) == fruitSet.end()){
                /// 构造可以装入的水果类型
                fruitSet.emplace(fruits[i]);
                i++;
            }else{
                if(fruits.size() == 2){
                    /// 两种情况
                    /// 1. 下一个水果是果篮中可以放入的
                    if(fruitSet.find(fruits[i]) != fruitSet.end()){

                    }else{
                        /// 2. 下一个水果是新出现的
                        if(i - curStart > res){ /// 更新最多可以采摘的水果数量
                            res = i - curStart;
                        }
                        curStart = i; /// 这个更新的不对
                        fruitSet.clear();
                        fruitSet.emplace(fruits[i-1]);
                        fruitSet.emplace(fruits[i]);
                    }

                }

            }
        }
    }
};

#endif //FH_A01_904_水果成篮_H
