#include <iostream>
#include "Solutions/Solution0063.h"
int main() {
    vector<vector<int>> board{vector<int>{1,0}};
    Solution solution;
    cout<<solution.uniquePathsWithObstacles(board)<<endl;
    return 0;
}
