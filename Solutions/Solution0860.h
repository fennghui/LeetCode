//
// Created by irisfeng on 2022/8/7.
//

#ifndef FH_A01_SOLUTION0860_H
#define FH_A01_SOLUTION0860_H

#include "../Common.h"
//860. 柠檬水找零 ez
//在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
//
//每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
//
//注意，一开始你手头没有任何零钱。
//
//给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cashNum(3,0);
        for(int i = 0; i < bills.size(); ++i){
            if(bills[i] == 5){
                cashNum[0]++;
                continue;
            }
            if(bills[i] == 10){
                if(cashNum[0] > 0){
                    cashNum[0]--;
                    cashNum[1]++;
                    continue;
                }
                return false;
            }
            if(bills[i]==20){
                if(cashNum[1]>0 && cashNum[0]>0){
                    cashNum[1]--;
                    cashNum[0]--;
                    cashNum[2]++;
                    continue;
                }
                if(cashNum[0]>2){
                    cashNum[0]-=3;
                    cashNum[2]++;
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};

#endif //FH_A01_SOLUTION0860_H
