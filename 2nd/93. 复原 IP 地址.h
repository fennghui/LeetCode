//
// Created by irisfeng on 2023/1/25.
//

#ifndef FH_A01_93_复原_IP_地址_H
#define FH_A01_93_复原_IP_地址_H

#include "../Common.h"

/**
 * "255.255.111.35"
 * "25525511135"
 */

class Solution {
public:
    vector<string> res;
    vector<string> path;

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12 || s.size() < 4) {
            return res;
        }

        backTracking(s, 1, 0, s.size());
        return res;
    }

    void backTracking(string &s, int nth_digit, int cur_index, int s_length) {
        if (nth_digit == 4) {
            int fourth_digit_length = s_length - cur_index;
            if(fourth_digit_length > 3){
                return;
            }
            string fourth_digit_str = s.substr(cur_index, fourth_digit_length);
            // cout << "4: "<<fourth_digit_str<<endl;
            path.push_back(fourth_digit_str);
            if (valid()) {
                // cout << "成功验证一个"<<endl;
                string tmp;
                for (int i = 0; i < path.size() - 1; i++) {
                    tmp += path[i];
                    tmp += '.';
                }
                tmp += path[path.size() - 1];
                res.push_back(tmp);
            }
            path.pop_back();
            return;
        }

        for (int i = 1; i <= 3; i++) {
            // cout<< "cur_index "<<cur_index<<endl;
            if(cur_index + i < s_length){
                string nth_digit_str = s.substr(cur_index, i);
                // cout<<nth_digit<<": "<<nth_digit_str<<endl;
                path.push_back(s.substr(cur_index, i));
                backTracking(s, nth_digit + 1, cur_index + i, s_length);
                path.pop_back();
            }
        }

    }

    bool valid() {
        // cout<<"ip.size: "<<path.size()<<endl;
        if (path.size() != 4) {
            // cout<<"数量不合法\n";
            return false;
        }
        /// 每一个数字是否合法
        for (int i = 0; i < path.size(); i++) {
            /// 是否有前导 0
            if(path[i].size() > 1 && path[i][0] == '0'){
                // cout<<"前导0不合法\n";
                return false;
            }
            /// 数字范围是否在 0 - 255 之间
            int tmp = stoi(path[i]);
            if(tmp > 255){
                // cout<<"数字范围不合法\n";
                return false;
            }
        }
        // cout<<"合法\n";
        return true;
    }

};

#endif //FH_A01_93_复原_IP_地址_H
