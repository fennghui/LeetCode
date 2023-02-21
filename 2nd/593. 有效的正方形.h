//
// Created by irisfeng on 2023/2/21.
//

#ifndef FH_A01_593_有效的正方形_H
#define FH_A01_593_有效的正方形_H

#include "../Common.h"

class Solution {
public:
    int edge = 0;
    double firstK = 0;

    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
        /// 四条边相等，且有一个角是直角，就是正方形
        vector<vector<int>> p{p1, p2, p3, p4};
        vector<bool> visited(4, false);
        visited[0] = true;
        for (int i = 1; i < 4; ++i) {
            int tmp1 = abs(p[0][0] - p[i][0]);
            int tmp2 = abs(p[0][1] - p[i][1]);
            edge = tmp1 * tmp1 + tmp2 * tmp2;
            firstK = (tmp1 == 0 || tmp2 == 0) ? 0 : 1.0 * tmp2 / tmp1;
            if (backTracking(p, visited, i, 1)) {
                return true;
            }
        }
        return false;
    }

    bool backTracking(vector<vector<int>> &p, vector<bool> &visited, int cur, int num) {
        if (num == 3) {
            int tmp1 = abs(p[cur][0] - p[0][0]);
            int tmp2 = abs(p[cur][1] - p[0][1]);
            if (tmp1 * tmp1 + tmp2 * tmp2 == edge && (tmp1 == 0 || tmp2 == 0) ? abs(0 - firstK) < 1e-6 :
                abs(1.0 * tmp2 / tmp1 * firstK - (-1)) < 1e-6) {
                return true;
            }
            return false;
        }

        visited[cur] = true;
        for (int i = 0; i < 4; ++i) {
            if (visited[i]) {
                continue;
            }
            int tmp1 = abs(p[cur][0] - p[i][0]);
            int tmp2 = abs(p[cur][1] - p[i][1]);
            if (tmp1 * tmp1 + tmp2 * tmp2 == edge) {
                if (backTracking(p, visited, i, num + 1)) {
                    return true;
                }
            }

        }
        visited[cur] = false;
        return false;
    }
};

#endif //FH_A01_593_有效的正方形_H
