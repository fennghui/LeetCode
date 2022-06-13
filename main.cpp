#include <iostream>
#include "Solutions/Solution2104.h"
int main() {
//    vector<vector<int>> board{vector<int>{1,0}};
    Solution solution;
    vector<int> temp{1,3,3};
    cout<<solution.subArrayRanges(temp)<<endl;
    return 0;
}
