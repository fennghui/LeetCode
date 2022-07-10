#include <iostream>
#include "Solutions/剑指 Offer 33.h"

int main() {
//    vector<vector<int>> board{vector<int>{1,0}};
    Solution solution;
    vector<vector<char>> vec1 {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<int> vec2{1,2,5,10,6,9,4,3};
    cout << solution.verifyPostorder(vec2);
    return 0;
}
