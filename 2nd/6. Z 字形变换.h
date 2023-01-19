//
// Created by irisfeng on 2023/1/19.
//

#ifndef FH_A01_6_Z_字形变换_H
#define FH_A01_6_Z_字形变换_H

#include "../Common.h"


/**
 * 4  2  4  2 4
 * P     I    N     
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (n < 2 || numRows < 2) {
            return s;
        }
        vector<string> res(numRows);
        int index = 0;
        int delta = -1;
        for (auto c : s) {
            res[index].push_back(c);
            if(index == 0 || index == numRows - 1) delta = -delta;
            index += delta;
        }

        string ret;
        for(int i = 0; i < numRows; i++){
            ret += res[i];
        }
        return ret;
    }
};

#endif //FH_A01_6_Z_字形变换_H
