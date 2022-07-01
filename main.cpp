#include <iostream>
#include "Solutions/剑指 Offer 07.h"

int main() {
//    vector<vector<int>> board{vector<int>{1,0}};
    Solution solution;
    vector<int> vec1{3, 1, 2, 4};
    vector<int> vec2{1, 2, 3, 4};
    output(solution.buildTree(vec1, vec2));
    return 0;
}
