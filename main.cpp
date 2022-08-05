#include <iostream>
#include "Solutions/Solution0122.h"

int main() {
//    vector<vector<int>> board{vector<int>{1,0}};
    Solution solution;
    vector<vector<char>> vec1{{'A', 'B', 'C', 'E'},
                              {'S', 'F', 'C', 'S'},
                              {'A', 'D', 'E', 'E'}};
    vector<int> vec2{8,6,4,3,3,2,3,5,8,3,8,2,6};
    auto result = solution.maxProfit(vec2);
    cout << result <<endl;
//    for (int i = 0; i < result.size(); ++i){
//        for(int j = 0; j < result[i].size(); ++j)
//            cout << result[i][j] << ", ";
//        cout<<endl;
//    }




    return 0;
}
