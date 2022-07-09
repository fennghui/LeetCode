#include <iostream>
#include "Solutions/剑指 Offer 63.h"

int main() {
//    vector<vector<int>> board{vector<int>{1,0}};
    Solution solution;
    vector<vector<char>> vec1 {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<int> vec2{7,1,5,3,6,4};
    solution.maxProfit(vec2);
    return 0;
}
