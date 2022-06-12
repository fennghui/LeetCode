#include <iostream>
#include "Solutions/Solution1005.h"
int main() {
//    vector<vector<int>> board{vector<int>{1,0}};
    Solution solution;
    vector<int> temp{2,-3,-1,5,-4};
    cout<<solution.largestSumAfterKNegations(temp, 2)<<endl;
    return 0;
}
