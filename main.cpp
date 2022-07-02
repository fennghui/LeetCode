#include <iostream>
#include "Solutions/剑指 Offer 13.h"

int main() {
//    vector<vector<int>> board{vector<int>{1,0}};
    Solution solution;
    vector<vector<char>> vec1 {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<int> vec2{1, 2, 3, 4};
    cout<<solution.movingCount(1,2,1);
    return 0;
}
